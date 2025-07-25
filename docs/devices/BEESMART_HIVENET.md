# BEESMART HiveNet Sensor Documentation

## Overview
The BEESMART HiveNet Sensor is a specialized bee hive monitoring device that transmits temperature, humidity, and battery voltage data via BLE (Bluetooth Low Energy) advertisements.

## BLE Advertisement Structure

The device follows a specific BLE advertisement format as described below:

### Complete Advertisement Payload Structure

```
Byte Index | Field                    | Length | Description
-----------|--------------------------|--------|------------
0-2        | Flags                   | 3      | BLE flags (0x02 0x01 0x04)
3-(N+4)    | Complete Local Name     | N+2    | Device name "BeeSmart" (N=8)
(N+5)-(N+M+6) | Manufacturer Data    | M+2    | Sensor data (M=8 bytes)
```

### Detailed Breakdown

#### 1. Flags (Bytes 0-2)
- **Length**: 0x02 (1 byte)
- **Type**: 0x01 (1 byte) - AD type for "Flags"
- **Value**: 0x04 (1 byte) - BT_LE_AD_NO_BREDR

#### 2. Complete Local Name (Bytes 3-11)
- **Length**: 0x09 (1 byte) - Length of type + value (1 + 8)
- **Type**: 0x09 (1 byte) - AD type for "Complete Local Name"
- **Value**: "BeeSmart" (8 bytes) - ASCII bytes: 0x42 0x65 0x65 0x53 0x6D 0x61 0x72 0x74

#### 3. Manufacturer Specific Data (Bytes 12-21)
- **Length**: 0x09 (1 byte) - Length of type + value (1 + 8)
- **Type**: 0xFF (1 byte) - AD type for "Manufacturer Specific Data"
- **Value**: 8 bytes of sensor data (see below)

### Sensor Data Format (8 bytes)

The 8-byte sensor data is structured as follows:

```
Byte Offset | Field        | Size | Format      | Description
------------|--------------|------|-------------|------------------
0-1         | Temperature  | 2    | Signed int  | Temperature in 0.01°C
2-3         | Humidity     | 2    | Unsigned    | Humidity in 0.01%
4-5         | Voltage      | 2    | Unsigned    | Battery voltage in mV
6-7         | Reserved     | 2    | -           | Reserved for future use
```

## Data Processing

### Temperature
- **Raw Format**: 16-bit signed integer (little-endian if reversed=true)
- **Processing**: Divide by 100 to get degrees Celsius
- **Range**: Typically -40°C to +85°C
- **Example**: Raw value 2573 → 25.73°C

### Humidity
- **Raw Format**: 16-bit unsigned integer
- **Processing**: Divide by 100 to get percentage
- **Range**: 0% to 100%
- **Example**: Raw value 6250 → 62.50%

### Battery Voltage
- **Raw Format**: 16-bit unsigned integer
- **Processing**: Direct value in millivolts
- **Range**: Typically 1800mV to 3600mV
- **Example**: Raw value 3300 → 3300mV (3.3V)

## Device Configuration

### Brand and Model
- **Brand**: BeeSmart
- **Model**: HiveNet Sensor
- **Model ID**: HNS01THB

### Tag Properties
- **Tag**: "0205"
  - Byte[0]: 0x01 - THB (Temperature, Humidity, Battery)
  - Byte[1]: 0x02 - Additional properties flags

### Condition Matching
The decoder identifies BEESMART HiveNet devices by:
1. Device name starts with "BeeSmart"
2. Manufacturer data is exactly 8 bytes

## Example Advertisement Data

```
Complete Advertisement: 0x02 0x01 0x04 0x09 0x09 0x42 0x65 0x65 0x53 0x6D 0x61 0x72 0x74 0x09 0xFF 0x0D 0x0A 0x6E 0x18 0xE4 0x0C 0x00 0x00

Breakdown:
- Flags: 02 01 04
- Name: 09 09 426565536D617274 ("BeeSmart")
- Mfg Data: 09 FF 0D0A6E18E40C0000
  * Temperature: 0x0A0D (2573) → 25.73°C
  * Humidity: 0x186E (6254) → 62.54%
  * Voltage: 0x0CE4 (3300) → 3300mV
  * Reserved: 0x0000
```

## Integration Notes

The BEESMART HiveNet Sensor decoder is integrated into TheengsDecoder by:
1. Adding the device definition in `BEESMART_HIVENET_json.h`
2. Including it in the main `devices.h` file
3. Adding the enum value to `decoder.h`
4. Adding the device to the `_devices` array

This enables automatic recognition and decoding of BEESMART HiveNet devices in any application using TheengsDecoder.
