// 
// Portenta H7 Identifier
//
// Original Author: A. Vidstrom
//
// This code is in the public domain
//

uint16_t boardRevision();
uint8_t bootloaderVersion();

void setup() {
  Serial.begin(9600);
  while (!Serial)
    ;
  Serial.print("Bootloader Version: ");
  Serial.println(bootloaderVersion());
  Serial.print("Board Revision    : ");
  Serial.print((boardRevision() & 0xff00) >> 8);
  Serial.print(".");
  Serial.println(boardRevision() & 0x00ff);
  Serial.print("MCU Revision      : ");
  const uint32_t revision = (DBGMCU->IDCODE & 0xffff0000) >> 16;
  Serial.print(revision, HEX);
  if (0x2001 == revision)
  {
    Serial.println(" (X)");
  }
  else if (0x2003 == revision)
  {
    Serial.println(" (V)");
  }
  else
  {
    Serial.println(" (Unknown)");
  }
  const uint32_t deviceId = DBGMCU->IDCODE & 0x000007ff;
  Serial.print("Device ID         : ");
  Serial.print(deviceId, HEX);
  if (0x0450 == deviceId)
  {
    Serial.println(" (STM32H745/747/755/757)");
  }
  else
  {
    Serial.println(" (Unknown)");
  }
}

void loop() {
}
