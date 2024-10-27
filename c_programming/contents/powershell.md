# PowerShell

## Getting Started


### バージョン

PowerShell のバージョンを確認するには、次のコマンドを実行します。

```powershell
$PSVersionTable
```

## ヘルプ

| Name       | Alias | Description | Example    |
| ---------- | ----- | ----------- | ---------- |
| `Get-Help` | `man` | Get help    | `Get-Help` |

## ファイルシステム

| Name            | Alias  | Description             | Example                    |
| --------------- | ------ | ----------------------- | -------------------------- |
| `Set-Location`  | `cd`   | Change directory        | `cd C:\`                   |
| `Get-Location`  | `pwd`  | Print working directory | `pwd`                      |
| `Get-ChildItem` | `dir`  | List directory contents | `dir`                      |
| `Copy-Item`     | `copy` | Copy item               | `cp file.txt C:\`          |
| `Move-Item`     | `move` | Move item               | `mv file.txt C:\`          |
| `Remove-Item`   | `del`  | Remove item             | `rm file.txt`              |
| `New-Item`      | `ni`   | Create new item         | `ni file.txt`              |
| `Rename-Item`   | `ren`  | Rename item             | `ren file.txt newfile.txt` |

### Set-Location

`Set-Location` コマンドレットは、カレントディレクトリを変更します。

```powershell
Set-Location C:\
```

使用できるエイリアスは以下の通りです。

- `cd`
- `chdir`
- `sl`

`cd ..` コマンドを使用して、親ディレクトリに移動します。

```powershell
cd ..
```

### Get-Location

`Get-Location` コマンドレットは、カレントディレクトリを取得します。

```powershell
Get-Location
```

使用できるエイリアスは以下の通りです。

- `pwd`
- `gl`

### Get-ChildItem

`Get-ChildItem` コマンドレットは、指定されたディレクトリ内のファイルとサブディレクトリのリストを取得します。

```powershell
Get-ChildItem
```

使用できるエイリアスは以下の通りです。

- `dir`
- `ls`

`-Recurse` パラメーターを使用して、サブディレクトリ内のファイルとディレクトリを再帰的に取得します。

```powershell
Get-ChildItem -Recurse
```

`-Filter` パラメーターを使用して、ファイル名のパターンを指定してファイルをフィルタリングします。

```powershell
Get-ChildItem -Filter *.txt
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




