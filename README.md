
                            Probabilistic Delta Debugging (ProbDD)
                                --- an instance of delta debugging
                                
              Guancheng Wang, Ruobing Shen, Junjie Chen, Yingfei Xiong and Lu Zhang
             
                Department of Computer Science and Technology, Peking University
                    College of Intelligence and Computing, Tianjin University
                                       

Please send issues and suggestions to <guancheng.wang@pku.edu.cn>.

Please see [our original paper](FSE2021__Probabilistic_Delta_Debugging_for_Review.pdf) to find most ProbDD info.


# ProbDD
![Maintenance](https://img.shields.io/badge/Maintained%3F-YES-green.svg)
![License](https://img.shields.io/badge/license-GPL-orange.svg)
![Environment](https://img.shields.io/badge/Environment-Docker-blue.svg)
![C++ 11](https://img.shields.io/badge/C++-11-4c7e9f.svg)
![Python 2](https://img.shields.io/badge/Python-2-4c7e9f.svg)
![platform](https://img.shields.io/badge/platform-Windows|Linux|MacOS-yellowgreen)

Here is the artifact of the paper **Probabilistic Delta Debugging**, which has been accepted by [ESEC/FSE 2021](https://2021.esec-fse.org/). The following table shows the important files and their purposes in this artifact, which may help you use the artifact with a good experience.

| File name | Purpose |
| :---- | :---- |
| [LICENSE](LICENSE)            | description of the distribution rights | 
| [README](README.md)              | guidance on how to read the documentation | 
| [STATUS](STATUS.md)              | the badges we are applying for and the reasons | 
| [CHANGES](CHANGES.md)            | code changes compared with the original tools | 
| [REQUIREMENTS](REQUIREMENTS.md)  | requirements needed with building from source | 
| [INSTALL](INSTALL.md)            | installation guidance needed with building from source | 

The artifact has two main purposes, and [this file](STATUS.md) states the badges we are applying for as well as the reasons why we believe that the artifact deserves the badges.
- The first purpose is to reproduce the main results in our original paper. More details in [Reproducing the main results](https://github.com/Amocy-Wang/ProbDD#reproducing-the-main-results).
- The second is to provide an implementation of ProbDD that can be used for delta debugging tasks beyond the evaluation dataset. More details in [Being used for delta debugging tasks](https://github.com/Amocy-Wang/ProbDD#being-used-for-delta-debugging-tasks).

## Reproducing the main results
---------------------------------------------------
In this section, we show how to reproduce the main results in our paper step by step, i.e., [preparing](https://github.com/Amocy-Wang/ProbDD/blob/main/README.md#preparing), [running tools](https://github.com/Amocy-Wang/ProbDD/blob/main/README.md#running-tools), and [analyzing results](https://github.com/Amocy-Wang/ProbDD/blob/main/README.md#analyzing-results). If you want to rapidly do this, please directly jump to the last part [An example workflow](https://github.com/Amocy-Wang/ProbDD/blob/main/README.md#an-example-workflow) in this section.

### Preparing
There are two ways to run ProbDD and reproduce the results on your machines. 
- ![Recommended](https://img.shields.io/badge/Recommended%3F-YES-green.svg) **Downloading Docker Image**. For macOS or Linux users, you can follow the following commands to get into the container. For Windows users, you need to download [docker desktop](https://www.docker.com/products/docker-desktop) and [Cygwin](https://www.cygwin.com/) first and make sure that there is no error message when the docker destop starts for the first time. Then, you need to open Cygwin and run the commands below. If there is any error messages, please follow the pop-up link to fix the problems. Usually, the problem is that BIOS disables cpu virtualization function. You can fix it by entering BIOS, enabling the function, and restarting.
```bash
# download the image package ProbDD.tar (with size 60.8G)
You can download the split files of Docker Image from <https://pan.baidu.com/s/1DEmnbNJdqpvuvvMSZecF3A> with password "pj9b".
# generate Image ProbDD.tar
cat ProbDD.tar.part-* > ProbDD.tar
# load as a Docker Image
docker load < ProbDD.tar # This process may take about 10 minutes depending on the machine performance. When the process finishes, the image id will show on the screen.
# get into the container
docker run --privileged -it [image id] /bin/bash 
```

- ![Recommended](https://img.shields.io/badge/Recommended%3F-NO-red.svg) **Building from Source Code**. The installation guidance is successfully tested on a machine with Ubuntu 16.04.7 LTS. The requirements are listed in [REQUIREMENTS](REQUIREMENTS.md). You can successfully build the tools and reproduce the evaluation by following the installation guidance in [INSTALL](INSTALL.md). We DO NOT recommend building from source because there are many dependencies needed by the tools and the subjects of benchmarks.

### Running tools
We also provide several scripts for running our tools. The used datasets in our paper and this artifact can be found at [compilerbugs](https://bitbucket.org/chengniansun/perses_c_benchmarks/src/master/) and [debloating](https://chisel.cis.upenn.edu/bench.html), respectively.
The following table shows these scripts and their functions.

| Script name | Function |
| :---- | :---- |
| [compilerbugs/runChisel_ProbDD](benchmarks/compilerbugs/runChisel_ProbDD.sh)           | evaluating Chisel with ProbDD with dataset compilerbugs|
| [compilerbugs/runChisel_activecoarsen](benchmarks/compilerbugs/runChisel_activecoarsen.sh)    | evaluating Chisel with ActiveCoarsen with dataset compilerbugs|
| [compilerbugs/runChisel_ddmin](benchmarks/compilerbugs/runChisel_ddmin.sh)            | evaluating the original Chisel with dataset compilerbugs|
| [compilerbugs/runHDD_ProbDD](benchmarks/compilerbugs/runHDD_ProbDD.sh)             | evaluating HDD with ProbDD with dataset compilerbugs|
| [compilerbugs/runHDD_activecoarsen](benchmarks/compilerbugs/runHDD_activecoarsen.sh)      | evaluating HDD with ActiveCoarsen with dataset compilerbugs|
| [compilerbugs/runHDD_ddmin](benchmarks/compilerbugs/runHDD_ddmin.sh)              | evaluating the original HDD with dataset compilerbugs|
| [chisel-bench/runChisel_ProbDD](benchmarks/chisel-bench/runChisel_ProbDD.sh)           | generating a clean working space and evaluating Chisel with ProbDD with dataset chisel-bench|
| [chisel-bench/runChisel_activecoarsen](benchmarks/chisel-bench/runChisel_activecoarsen.sh)    | generating a clean working space and evaluating Chisel with ActiveCoarsen with dataset chisel-bench|
| [chisel-bench/runChisel_ddmin](benchmarks/chisel-bench/runChisel_ddmin.sh)            | generating a clean working space and  evaluating the original Chisel with dataset chisel-bench|

To process subjects, you need:
- Get into the working directory where the scripts are located. If you use the Docker Image, the working directories are /benchmarks/compilerbugs and /benchmarks/chisel-bench for dataset compilerbugs and chisel-bench, respectively.
- run the scripts
```bash
# Option1: process subjects in compilerbugs
cd /benchmarks/compilerbugs
# If you want to run Chisel based tools, here we take an example for using Chisel with ProbDD.
./runChisel_ProbDD.sh
# If you want to run HDD based tools, here we take an example for using HDD with ProbDD.
./runHDD_ProbDD.sh

#Option2: process subjects in chisel-bench. The default running tool is chisel_ProbDD, if you want to change the tool, you need to modify the tool path in /benchmarks/chisel-bench/benchmark/target.mk (line 9).
cd /benchmarks/chisel-bench
# Run the tool. Here we take an example for using Chisel with ProbDD.
./runChisel_ProbDD.sh
```

### Analyzing results
We provide several scripts to conveniently collect results and generate a report for each subject processed by the tools. The scripts are written in Python-2.7, so you need to run them with Python-2.7.
The following table shows these scripts and their functions. The first and the third scripts need a parameter, which is the name of the log file.

| Script name | Function |
| :---- | :---- |
| [compilerbugs/generate_ChiselReport](benchmarks/compilerbugs/generate_ChiselReport.py)           | should be invoked after executing the script compilerbugs/runChisel_XXX to collect token number and processing time for each subject in compilerbugs processed by Chisel based tools|
| [compilerbugs/generate_HDDReport](benchmarks/compilerbugs/generate_HDDReport.py)           | should be invoked after executing the script compilerbugs/runHDD_XXX to  collect token number and processing time for each subject in compilerbugs processed by HDD based tools|
| [chisel-bench/generate_ChiselReport](benchmarks/chisel-bench/generate_ChiselReport.py)           | should be invoked after executing the script chisel-bench/runChisel_XXX to  collect token number and processing time for each subject in chisel-bench processed by Chisel based tools|

### An example workflow
In this part, we take an example for using ProbDD to process a subset of subjects in both datasets and generating the report on the returned number of tokens and the processing time for each processed subject. 
For demonstration, we add a prefix 'workflow-' to the corresponding scripts. If you want a complete validation and verification (this may take a very long time), just follow the steps without this prefix.

```bash
# Step1: process subjects in compilerbugs by using Chisel with ProbDD
cd /benchmarks/compilerbugs/
./workflow-runChisel_ProbDD.sh # A set of four subjects will be processed. 
python workflow-generate_ChiselReport.py workflow-chisel_ProbDD.out # A file named resfile.csv will be generated in the working directory after executing this command.

# Step2: process subjects in compilerbugs by using HDD with ProbDD
./workflow-runHDD_ProbDD.sh
python workflow-generate_HDDReport.py # The results will be printed onto the screen. If a subject is processed with time out, the value of time field will be empty.

# Step3: process subjects in chisel-bench by using Chisel with ProbDD
cd /benchmarks/chisel-bench/
./workflow-runChisel_ProbDD.sh
python workflow-generate_ChiselReport.py workflow-chisel_ProbDD.out # The results will be printed onto the screen. If a subject is processed with time out, the value of time field will be empty.
```

## Being used for delta debugging tasks
-----------------------------------------------------------

Next, we show that how ProbDD can be used for delta debugging tasks beyond the evaluation dataset. When a set of elements and a test function is provided, it reduces the elements to a smaller set. We also prepare a set of subjects (which are not contained in the evaluation dataset) as examples. 

To add a new subject, one needs the following
- entering a directory, where you want to put your subject (assuming */examples/new/* for an example)
- a C program (named *small`.`origin`.`c* for an example)
- a script specified the properties that the given C program exhibits (named *test`.`sh* for an example)

Do the following to run the new subject with **Chisel with ProbDD** and **HDD with ProbDD**:
```bash
# First, check whether the given program exhibits the properties in the script.
cd /examples/new
cp small.origin.c small.c # backup
./test.sh
echo $? # If the given program does exhibit the properties, 0 should be returned.

# Step1: Run with the tool Chisel with ProbDD
/chisel_ProbDD/build/bin/chisel --skip_local_dep --skip_global_dep --skip_dce test.sh small.c # The returned file is small.c, and the returned number of tokens and the processing time are shown in the end of the log.

# Step2: Run with the tool HDD with ProbDD
/hdd_ProbDD/anaconda2/bin/picireny -i small.c --test test.sh --srcml:language C --grammar C.g4 --start compilationUnit --disable-cleanup # The returned file is small.c, and the processing time are shown in the end of the log. A directory named with prefix small.c.2021 will be generated and the returned C program is saved in it.

# Step2-1: Get the returned number of tokens by HDD with ProbDD
/countTokens/build/bin/chisel small.c.2021-XXX/small.c small.c.2021-XXX/small.c # The directory small.c.2021-XXX is generated in Step2.
```

## Acknowledgement
------------------

### We thank all the reviews for their thoughtful comments and efforts towards improving our paper.

### We benifted a lot from the following projects when building ProbDD.
- [Delta Debugging](https://www.st.cs.uni-saarland.de/dd/): a homepage of Delta Debugging project maintained by Prof. Andread Zeller.
- [Chisel](https://chisel.cis.upenn.edu/): a system for Debloating C/C++ Programs. Proposed in the paper **Effective Program Debloating via Reinforcement Learning**.
- [Picireny](): an instance of Hierarchical Delta Debugging Framework (HDD).
