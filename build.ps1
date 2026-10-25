param([string]$Preset = "debug", [switch]$Run)
$ErrorActionPreference = "Stop"

if (-not $env:VSCMD_VER) {
    $vswhere = "${env:ProgramFiles(x86)}\Microsoft Visual Studio\Installer\vswhere.exe"
    $vs = & $vswhere -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath
    Import-Module "$vs\Common7\Tools\Microsoft.VisualStudio.DevShell.dll"
    Enter-VsDevShell -VsInstallPath $vs -SkipAutomaticLocation -DevCmdArguments "-arch=x64 -host_arch=x64" | Out-Null
}

if (-not (Test-Path "build/$Preset/build.ninja")) {
    cmake --preset $Preset
    if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }
}

cmake --build --preset $Preset
if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }

if ($Run) {
    Push-Location build/${Preset}/bin
    ./portoil.exe
    Pop-Location
}

exit $LASTEXITCODE
