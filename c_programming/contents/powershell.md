# PowerShell

## Getting Started

### バージョン

PowerShell のバージョンを確認するには、次のコマンドを実行します。

```powershell
$PSVersionTable
```

PowerShell のバージョンが5.1以下の場合、最新のバージョンにアップグレードすることをお勧めします。

### Cmdlet について
- PowerShell は、cmdlet（コマンドレット）と呼ばれるコマンドを使用します。
- コマンドレットは、`Verb-Noun` の形式で構成されます。例えば、`Get-Process` は、プロセスの情報を取得するコマンドレットです。
- コマンドレットのパラメーターは、`-ParameterName` の形式で指定します。例えば、`Get-Process -Name "chrome"` は、名前が `chrome` のプロセスの情報を取得するコマンドです。
- コマンドレットのAlias（エイリアス）は、短縮形で使用できます。例えば、`Get-Process` は、`gps` としても使用できます。
- PowerShell は、基本的に大文字と小文字を区別しません。

### 便利な操作

- `Tab` キーを押すと、コマンドの補完ができます。
- `Up Arrow` キーを押すと、前のコマンドを表示できます。
- `Down Arrow` キーを押すと、次のコマンドを表示できます。
- `Ctrl + C` キーを押すと、コマンドの実行を中止できます。

## ヘルプ

| Name       | Alias | Description | Example    |
| ---------- | ----- | ----------- | ---------- |
| `Get-Help` | `man` | Get help    | `Get-Help` |

## ファイルシステム

| Name            | Alias               | Description             | Example                    |
| --------------- | ------------------- | ----------------------- | -------------------------- |
| `Set-Location`  | `cd`, `chdir`, `sl` | Change directory        | `cd C:\`                   |
| `Get-Location`  | `pwd`, `gl`         | Print working directory | `pwd`                      |
| `Get-ChildItem` | `dir`, `ls`         | List directory contents | `dir`                      |
| `New-Item`      | `ni`                | Create new item         | `ni file.txt`              |
| `Rename-Item`   | `ren`               | Rename item             | `ren file.txt newfile.txt` |
| `Copy-Item`     | `copy`              | Copy item               | `cp file.txt C:\`          |
| `Move-Item`     | `move`              | Move item               | `mv file.txt C:\`          |
| `Get-Content`   | `gc`                | Get item content        | `gc file.txt`              |
| `Remove-Item`   | `del`               | Remove item             | `rm file.txt`              |

### Set-Location

`Set-Location` コマンドレットは、カレントディレクトリを変更します。

```powershell
Set-Location C:\
```

`Set-Location ..` コマンドを使用して、親ディレクトリに移動します。

```powershell
Set-Location ..
```

### Get-Location

`Get-Location` コマンドレットは、カレントディレクトリを取得します。

```powershell
Get-Location
```

### Get-ChildItem

`Get-ChildItem` コマンドレットは、指定されたディレクトリ内のファイルとサブディレクトリのリストを取得します。

```powershell
Get-ChildItem
```

`-Path` パラメーターを使用して、指定されたディレクトリ内のファイルとサブディレクトリのリストを取得します。

```powershell
Get-ChildItem -Path C:\
```

`-Recurse` パラメーターを使用すると、全てのサブディレクトリを再帰的に取得します。`-Depth` パラメーターを使用して、再帰の深さを指定できます。ここでは、1 つのサブディレクトリまで取得します。

```powershell
Get-ChildItem -Recurse -Depth 1
```

`-Force` パラメーターを使用して、非表示の項目を含むすべての項目を取得します。

```powershell
Get-ChildItem -Force
```

`-Filter` パラメーターを使用して、指定されたフィルターに一致する項目のみを取得します。次の例では、拡張子が `.txt` のファイルのみを取得します。

```powershell
Get-ChildItem -Filter *.txt
```

### New-Item

`New-Item` コマンドレットは、新しいファイル、ディレクトリを作成します。

以下の例は、現在のディレクトリにファイル `test.txt` を作成します。

```powershell
New-Item test.txt
```

`-ItemType` パラメーターを使用して、新しい項目の種類を指定できます。`File` はファイル、`Directory` はディレクトリを指定します。

```powershell
New-Item test -ItemType Directory
```

`-Path` パラメーターを使用して、新しい項目の場所を指定できます。`-Name` パラメーターを使用して、新しい項目の名前を指定できます。`-Value` パラメーターを使用して、新しいファイルの内容を指定できます。

以下の例は、`C:\test` ディレクトリにファイル `test.txt` を作成し、内容を `Hello, World!` とします。

```powershell
New-Item -Path C:\test -Name test.txt -ItemType File -Value "Hello, World!"
```

### Rename-Item

`Rename-Item` コマンドレットは、ファイルまたはディレクトリの名前を変更します。

以下の例は、`test.txt` ファイルを `newtest.txt` にリネームします。

```powershell
Rename-Item -Path "C:\test\test.txt" -NewName "newtest.txt"
```

ここで、`test.txt` ファイルが存在しない場合、次のエラーメッセージが表示されます。`C:\test\test.txt` が存在しないため、リネームできません。

```bash
Rename-Item : Cannot rename because item at 'C:\test\test.txt' does not exist.
```

### Copy-Item

`Copy-Item` コマンドレットは、ファイルまたはディレクトリを別の場所にコピーします。

以下の例は、`test.txt` ファイルを `C:\` ディレクトリにコピーします。

```powershell
Copy-Item -Path "C:\test\test.txt" -Destination "C:\test2"
```

### Move-Item

`Move-Item` コマンドレットは、ファイルまたはディレクトリを別の場所に移動します。

以下の例は、`test.txt` ファイルを `C:\test2` ディレクトリに移動します。

```powershell
Move-Item -Path "C:\test\test.txt" -Destination "C:\test2"
```

### Get-Content

`Get-Content` コマンドレットは、ファイルの内容を取得します。

以下の例は、`test.txt` ファイルの内容を取得します。

```powershell
Get-Content test.txt -Path C:\test\test.txt
```

### Remove-Item

`Remove-Item` コマンドレットは、ファイルまたはディレクトリを削除します。

以下の例は、`test.txt` ファイルを削除します。

```powershell
Remove-Item -Path C:\test\test.txt
```



## ネットワーク

| Name                     | Description             | Example                                 |
| ------------------------ | ----------------------- | --------------------------------------- |
| `Test-Connection`        | Test network connection | `Test-Connection www.example.com`       |
| `Test-NetConnection`     | Test network connection | `Test-NetConnection`                    |
| `Resolve-DnsName`        | Resolve DNS name        | `Resolve-DnsName -name www.example.com` |
| `Get-NetIPConfiguration` | Get IP configuration    | `Get-NetIPConfiguration`                |
| `Get-NetTCPConnection`   | Get TCP connection      | `Get-NetTCPConnection`                  |
| `Get-NetAdapter`         | Get network adapter     | `Get-NetAdapter`                        |

### Test-Connection

`Test-Connection` コマンドレットは、ICMP　エコー要求パケット（Ping）を一つ以上のコンピューターに送信します。特定のコンピューターにIPネットワーク経由で接続できるかどうかを判断できます。

```powershell
Test-Connection www.example.com
```

`-Count` パラメーターを使用して、送信するエコー要求パケットの数を指定できます。

```powershell
Test-Connection www.example.com -Count 4
```

`-Quiet` パラメーターを使用して、テストの結果をbool値で返します。

```powershell
Test-Connection www.example.com -Quiet
```

### Test-NetConnection

`Test-NetConnection` コマンドレットは、ネットワーク接続の診断情報を提供します。

下記の例は、デフォルトのサーバーに対してPingテストを実行します。

```powershell
Test-NetConnection
```

`-Port` パラメーターを使用して、デフォルトのサーバーに対して特定のポートに接続テストを実行します。

```powershell
Test-NetConnection -Port 80
```

`-CommonTCPPort` パラメーターを使用して、デフォルトのサーバーに対して一般的なTCPポートに接続テストを実行します。

```powershell
Test-NetConnection -CommonTCPPort HTTP
```

`-ComputerName` パラメーターを使用して、remote computer に対してPingテストを実行します。

```powershell
Test-NetConnection -ComputerName www.example.com
```

`-TraceRoute` パラメーターを使用して、パケットがネットワーク上でどのように移動するかを示す情報を提供します。

```powershell
Test-NetConnection -ComputerName www.example.com -TraceRoute
```

### Resolve-DnsName

`Resolve-DnsName` コマンドレットは、名前解決を実行します。


以下の例は、[www.example.com](http://www.example.com) のIPアドレスを求めます。

```powershell
Resolve-DnsName -name www.example.com
```

`-Type` パラメーターを使用して、特定のDNSレコードタイプを指定できます。`A` はIPv4 アドレスを指定、`AAAA` はIPv6 アドレスを指定します。

```powershell
Resolve-DnsName -name www.example.com -Type A
```

### Get-NetIPConfiguration

`Get-NetIPConfiguration` コマンドレットは、ネットワークアダプターのIP設定情報を取得します。

```powershell
Get-NetIPConfiguration
```

### Get-NetTCPConnection

`Get-NetTCPConnection` コマンドレットは、TCP接続の情報を取得します。

```powershell
Get-NetTCPConnection
```

`-State` パラメーターを`Established` に設定して、確立されたTCP接続の情報を取得します。

```powershell
Get-NetTCPConnection -State Established
```

### Get-NetAdapter

`Get-NetAdapter` コマンドレットは、ネットワークアダプターの情報を取得します。`Get-NetAdapter` コマンドレットを使用して、ネットワークアダプターの名前、MACアドレス、LinkSpeed、状態などの情報を取得できます。

```powershell
Get-NetAdapter
```




