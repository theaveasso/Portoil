param([switch]$Run, [int]$Port = 8080)
$ErrorActionPreference = "Stop"

if (-not $env:EMSDK) { & C:\emsdk\emsdk_env.ps1 | Out-Null }

./build.ps1 -Preset web
if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }

if ($Run) {
    emrun --port $Port build/web/bin/portoil.html
}
