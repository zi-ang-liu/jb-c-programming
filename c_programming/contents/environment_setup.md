# 環境構築

プログラミングの講義を受講するために，はじめに各⾃のコンピュータにC⾔語の開発環境を構築する必要があります．

環境構築には、**コンパイラ**と**エディタ**が必要です．本年度のプログラミングの講義では，WindowsコンピュータではMinGWを，MacコンピュータではClang/LLVMをそれぞれインストールした開発環境をもとに⾏います．エディタについては，Visual Studio Codeを使用します．

|   OS    | コンパイラ |      エディタ      |
| :-----: | :--------: | :----------------: |
| Windows |   MinGW    | Visual Studio Code |
|   Mac   | Clang/LLVM | Visual Studio Code |

以下の⼿順に従って，各⾃で開発環境を構築してください．

### MinGW，Command Line Tools for Xcode とは？

MinGW（ミン・ジー・ダブリュー，Minimalist GNU for Windows）は，C ⾔語などのコンパイラの環境を Windows 上で実現するためのフリーのアプリケーションの⼀つです．

MinGW(Wikipedia)：https://ja.wikipedia.org/wiki/MinGW

Xcode（エックスコード）とはmacOSにおける統合開発環境です．この環境で開発を行うためのコマンドラインツール群をCommand Line Tools for Xcodeと呼びます．

Xcode(Wikipedia)：https://ja.wikipedia.org/wiki/Xcode

それぞれフリーで使えるアプリケーションです．それぞれのインストール⽅法の概要を以下に⽰します．インストールについては参考となる情報がインターネットに多くありますので，以下の資料で分からない点がありましたら，まずはインターネットで調べてみてください．

## コンパイラのインストール

### Windows

### Mac

Macのコンピュータについては，`Clang/LLVM` コンパイラを使用します．

すでにインストールされているかどうかを確認するために，ターミナルを開いて以下のコマンドを実行してください．

（ターミナルは，Finderから`アプリケーション` -> `ユーティリティ` -> `ターミナル` で開くことができます。また，Spotlight検索で`terminal`と入力しても開くことができます。）

```bash
clang --version
```

バージョン情報が表示されれば，すでにインストールされています．次のセクションに進んでください．

インストールされていない場合は，ターミナルで以下のコマンドを実行してください．

```bash
xcode-select --install
```

コマンドを実行した後に表示される案内に従って操作を進めるとCommand Line Tools for Xcode がインストールされ，`clang`が使えるようになります．

確認のために，再度以下のコマンドを実行してください．

```bash
clang --version
```

## Visual Studio Codeのインストール

Visual Studio Code（以下，VS Code）は，Microsoftが提供するオープンソースのコードエディタです．C言語だけでなく，pythonやjavaなどの多くのプログラミング言語に対応しています．

### インストール

VS codeのサイト（https://code.visualstudio.com/）からインストーラをダウンロードしてください．OSに合わせて**Download for Windows**または**Download for Mac**をクリックするとダウンロードが始まります．


### 拡張機能のインストール

VS Codeを起動し，左側のアイコンから`Extensions`をクリックしてください．検索バーに`C/C++`と入力し，表示された`C/C++`をクリックしてください．`Install`ボタンをクリックするとインストールが始まります．

インストールが完了したら，VS Codeを再起動してください．