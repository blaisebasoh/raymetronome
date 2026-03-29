Write-Host "Configuring Project..." -ForegroundColor Cyan
cmake --preset mingw-debug

if ($LASTEXITCODE -ne 0) {
    Write-Host "Configuration Failed!" -ForegroundColor Red
    exit $LASTEXITCODE
}

Write-Host "Building Project..." -ForegroundColor Cyan
cmake --build build

if ($LASTEXITCODE -eq 0) {
    Write-Host "Build Successful! Launching..." -ForegroundColor Green
    ./build/raymetronome.exe
} else {
    Write-Host "Build Failed!" -ForegroundColor Red
}
