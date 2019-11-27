# Blawn

Pleasant Programming Language.

...Do you feel "Blue" from Blawn?

# Warning
まだ開発途上なんでほんとに自己責任で使ってください。
Blawnの使用によっていかなる損害が出たとしても一切の責任を認めません。

# Documentation
そのうち書きまーす

# Usage
## Installing
GitHub使い方よくわかんないので実行ファイルも全部アップされちゃってます。
なのでそちらをダウンロードして頂ければ簡単に使えると思います。
## compile from source
やめたほうがいいです。どうしてもやりたければLLVM6.0,bison,flexをインストールしてから
buildディレクトリで"make"してください。"make -j8"とかにするとコンパイルが早くなります。
# Introduction To Blawn
そのうち書くはずなんで待ってて下さい。


⚠️動的配列の実装はまだアップロードされていなかったので
近いうちにcommitします

# Build 

## Requirement

- Ubuntu Linux 18.04 (or later?)
- llvm (6.0 or later)
  - `$ sudo apt install llvm`
- clang (6.0 or later)
  - `$ sudo apt install clang`
- GNU flex
  - `$ sudo apt install flex`
- GNU bison
  - `$ sudo apt install bison`
- GNU make
  - `$ sudo apt install make`
- gcc (g++)
  - `$ sudo apt install g++`
- cmake
  - `$ sudo apt install cmake`

- Fedora 29
- llvm(6.0 or later)
  - `$ sudo dnf install llvm llvm-devel`
- clang(6.0 or later)
  - `$ sudo dnf install clang`
- GNU flex
  - `$ sudo dnf install flex`
- GNU bison
  - `$ sudo dnf install bison`
- GNU make
  - `$ sudo dnf install make`
- gcc(g++)
  - `$ sudo dnf install g++`
- cmake(3.10 or later)
  - `$ sudo dnf install cmake`
- Ninja(optional)
  - `$ sudo dnf install ninja-build`


## Instructions

```
$ mkdir build
$ cmake .. (optional arguments -> -G Ninja -DCMAKE_CXX_COMPILER=clang++)
$ make (alternative command -> ninja)
```

# Run

```
$ cd build/bin
$ echo 'print("Hello")' > hello.blawn
$ ./blawn hello.blawn
```
