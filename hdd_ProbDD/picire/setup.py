# Copyright (c) 2016-2020 Renata Hodovan, Akos Kiss.
#
# Licensed under the BSD 3-Clause License
# <LICENSE.rst or https://opensource.org/licenses/BSD-3-Clause>.
# This file may not be copied, modified, or distributed except
# according to those terms.

from setuptools import find_packages, setup


def picire_version():
    def _version_scheme(version):
        return version.format_with('{tag}')

    def _local_scheme(version):
        if version.exact and not version.dirty:
            return ''
        parts = ['{distance}'.format(distance=version.distance)]
        if version.node:
            parts.append('{node}'.format(node=version.node))
        if version.dirty:
            parts.append('d{time:%Y%m%d}'.format(time=version.time))
        return '+{parts}'.format(parts='.'.join(parts))

    return { 'version_scheme': _version_scheme, 'local_scheme': _local_scheme }


setup(
    name='picire',
    packages=find_packages(),
    url='https://github.com/renatahodovan/picire',
    license='BSD',
    author='Renata Hodovan, Akos Kiss',
    author_email='hodovan@inf.u-szeged.hu, akiss@inf.u-szeged.hu',
    description='Picire Parallel Delta Debugging Framework',
    long_description=open('README.rst').read(),
    install_requires=['chardet', 'psutil', 'setuptools'],
    zip_safe=False,
    include_package_data=True,
    setup_requires=['setuptools_scm'],
    use_scm_version=picire_version,
    entry_points={
        'console_scripts': ['picire = picire.cli:execute']
    },
    classifiers=[
        'Intended Audience :: Developers',
        'License :: OSI Approved :: BSD License',
        'Operating System :: OS Independent',
        'Programming Language :: Python',
        'Programming Language :: Python :: 2',
        'Programming Language :: Python :: 2.7',
        'Programming Language :: Python :: 3',
        'Programming Language :: Python :: 3.5',
        'Programming Language :: Python :: 3.6',
        'Programming Language :: Python :: 3.7',
        'Programming Language :: Python :: 3.8',
        'Programming Language :: Python :: 3.9',
        'Topic :: Software Development :: Testing',
    ],
)
