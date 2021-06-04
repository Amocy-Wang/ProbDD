# Copyright (c) 2016-2019 Renata Hodovan, Akos Kiss.
#
# Licensed under the BSD 3-Clause License
# <LICENSE.rst or https://opensource.org/licenses/BSD-3-Clause>.
# This file may not be copied, modified, or distributed except
# according to those terms.

import logging

from . import config_iterators
from . import config_splitters
from .abstract_probdd import AbstractProbDD
from .outcome_cache import ConfigCache

logger = logging.getLogger(__name__)


class ProbDD(AbstractProbDD):

    def __init__(self, test, cache=None, id_prefix=(), split=config_splitters.zeller,
                 subset_first=True, subset_iterator=config_iterators.forward, complement_iterator=config_iterators.forward):
        """
        Initialize a ProbDD object.
        :param test: A callable tester object.
        :param cache: Cache object to use.
        :param id_prefix: Tuple to prepend to config IDs during tests.
        :param split: Splitter method to break a configuration up to n parts.
        :param subset_first: Boolean value denoting whether the reduce has to
            start with the subset-based approach or not.
        :param subset_iterator: Reference to a generator function that provides
            config indices in an arbitrary order.
        :param complement_iterator: Reference to a generator function that
            provides config indices in an arbitrary order.
        """
        cache = cache or ConfigCache()
        AbstractProbDD.__init__(self, test, split, cache=cache, id_prefix=id_prefix)

    def _processElementToPreserve(self,toBePreserve):
        tmp = []
        for history in self.testHistory:
            if self._intersect(toBePreserve, history):
                cha = self._minus(history, toBePreserve)
            else:
                tmp.append(history)
        self.testHistory = tmp
        for elm in toBePreserve:
            self.p[elm] = 1

    def _process(self,config,outcome):
        tmp=[]
        toBePreserve=[]
        if outcome==self.PASS:
            for history in self.testHistory:
                if self._intersect(config,history):
                    cha=self._minus(history,config)
                    if len(cha)==1:
                        if not(cha[0] in toBePreserve):
                            toBePreserve.append(cha[0])
                    else:
                        tmp.append(cha)
                else:
                    tmp.append(history)
            self.testHistory=tmp
            self._processElementToPreserve(toBePreserve)
        elif outcome==self.FAIL:
            self._processElementToPreserve(config)
