Option 1: Using Docker Image
=======================
To get into the container, you need:
- Download the Docker Image ProbDD.tar. You can download the image in the form of **splitted files (about 61G)** from <https://pan.baidu.com/s/1DEmnbNJdqpvuvvMSZecF3A> (password "pj9b") or **compressed package (about 18G)** <https://pan.baidu.com/s/1GPgwrV6HNF8v4zXEUfbB-A> (password "uhyi") or <https://www.icloud.com/iclouddrive/0DmUGMLPbyl1RxS6v0FlgWKZQ#ProbDD.tar>.
- Generate Image data file ProbDD.tar by using command "cat ProbDD.tar.part-* > ProbDD.tar" or "unzip ProbDD.tar.zip" depending on the form of downloaded files.
- docker load < ProbDD.tar
- docker run --privileged -it [image id]

Option 2: Installing From Sources
=======================
## Step 1: Installing dependencies needed by Chisel and Chisel
Before installing, you need:

```bash
# install basic dependencies
$ sudo apt-get --assume-yes update
$ sudo apt-get --assume-yes install vim tmux autoconf automake bison build-essential clang doxygen flex g++ git libncurses5-dev libtool libsqlite3-dev make mcpp python sqlite zlib1g-dev subversion tree iotop gawk m4 zsh gcc-multilib g++-multilib libssl-dev libpcre3 libpcre3-dev
```
To compile Chisel, you need:
- [CMake](https://cmake.org/) (version >= 3.19.3). Download source, build, and install CMake.
- boost library. Install by executing command 'sudo apt-get install libboost-all-dev'.
- armadillo library. Install by executing command 'sudo apt-get install libarmadillo-dev'.
- [mlpack](https://github.com/mlpack/mlpack) (version >= 3.4.2). Download source, build, and install mlpack library.
- [spdlog](https://github.com/gabime/spdlog) (version >= 1.3.1). Download source, build, and install spdlog library.
- [LLVM](https://llvm.org/) (version == 8.0.0). Install by executing commands 'wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key | apt-key add -' and 'sudo apt-get install clang-8 libclang-8-dev llvm-8-dev'.

Then, you can successfully build and install the tools built upon Chisel, i.e., Chisel with ddmin, Chisel with ProbDD, and Chisel with ActiveCoarsen.
```bash
cd /chisel
mkdir build && cd build
cmake ../
make
```

## Step 2: Installing dependencies needed by HDD and HDD
Before installing, you need:
- [anaconda2](https://www.anaconda.com).

Then, you can successfully install HDD, i.e., picire and picireny.
```bash
# install picire
cd /hdd_ProbDD/picire
/hdd_ProbDD/anaconda2/bin/python setup.py install
# install picireny
cd /hdd_ProbDD/picireny
/hdd_ProbDD/anaconda2/bin/python setup.py install
```

## Step 3: Installing dependencies needed by the subjects
To successfully build GCC verions, you need:
- [gmp library](https://gmplib.org/) (version >= 6.1.2).
- [mpfr library](https://www.mpfr.org/) (version >= 4.1.0).
- [mpc library](ftp://ftp.gnu.org/gnu/mpc) (version >= 1.1.0).

We provide a series of commands to install the above libraries.
```bash
cd path/to/save/source/code
# download source
wget https://gmplib.org/download/gmp/gmp-6.1.2.tar.bz2
wget https://www.mpfr.org/mpfr-4.1.0/mpfr-4.1.0.tar.gz
wget ftp://ftp.gnu.org/gnu/mpc/mpc-1.1.0.tar.gz 
# unzip the source package
tar xvf gmp-6.1.2.tar.bz2
tar xvf mpfr-4.1.0.tar.bz2
tar xvf mpc-1.1.0.tar.gz
# install 
cd path/to/save/source/code/gmp-6.1.2 && ./configure --prefix=path/to/install/gmp-6.1.2 && make -j4 && make install
cd path/to/save/source/code/mpfr-4.1.0 && ./configure --prefix=path/to/install/mpfr-4.0.2 --with-gmp=path/to/install/gmp-6.1.2 && make -j4 && make install
cd path/to/save/source/code/mpc-1.1.0 && ./configure --prefix=path/to/install/mpc-1.1.0 --with-gmp=path/to/install/gmp-6.1.2 --with-mpfr=path/to/install/mpfr-4.1.0 && make -j4 && make install
```

To successfully run the tools with all the subjects, you need:
- LLVM versions 3.6.0, 3.7.0, and 3.8.0. 
- GCC versions 4.8.0, 4.8.2, and 4.9.0.
- [CompCert](https://compcert.org/) (version >= 3.8.0)
