# Twitter API Checker

## 概要 (Overview)

あなたのTwitter開発者アカウントのAPIキーが有効であるかどうかを確認するためのツールです。Bot開発等にお役立ていただけます。

## 動作要件 (Requirements)
OS : Linux or Windows

（ただしあまり古いVersionは動作確認できていません）

## 使い方 (How to Use)

0.　以下からダウンロードします。

https://github.com/s51517765/etc/releases/download/2022-12-23/TwitterApiChecker.zip

1.　ダウンロードした.exeファイルとsetting.txtを任意の同一フォルダに保存します。

2.　setting.txtにあなたのAPIキー等を記入します。

以下のように、改行区切りでキーの名前、コロン、キーのように記入します。
```
API_KEY:xxxxxxxxxxxxxxxxxxxxxxxxx
API_KEY_SECRET:xxxxxxxxxxxxxxxxxxxxxxxxx
ACCESS_TOKEN:xxxxxxxxxxxxxxxxxxxxxxxxx
ACCESS_TOKEN_SECRET:xxxxxxxxxxxxxxxxxxxxxxxxx
```


3.　.exeを実行します。

    Linuxでは.exeを保存したフォルダに移動し、./TwitterApiTest-linux.exe とします。

    Windwsではコマンドラインを立ち上げ、<cd フォルダ名> で.exeのあるフォルダへ移動します。

    .exeファイルをコマンドラインへドラッグ＆ドロップし、Enterを押下します。

4.　結果が出力されます。

## ライセンス (License)

This software is released under the MIT License, see LICENSE.