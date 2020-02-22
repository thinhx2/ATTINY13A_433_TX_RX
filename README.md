# 433 MHz lib for ATTINY13A by using Arduino platform

- Project is NOT complete
&nbsp;

#### Communication distance test (direct visibility) by using antennas

| **Distance** | **Msg. lost** |
|--------------|---------------|
|   **25 m**   |  about 10%    |
|   **40 m**   |  about 60%    |

*This measure is not exact. It dependent on many factors*

## Customize of Lib VirtualWire to VirtualWire_TX
##### Lib VirtualWire_TX in folder "433/transmitter/.."

|       **Lib**     | **Size (bytes)** |
|-------------------|------------------|
|**VirtualWire**    |  2200    |
|**VirtualWire_TX** |  2338    |

- *VirtualWire_TX is NOT smaller and is not under 1KB*
- *We will have to fix some variables for optimization of code (size of compiled binary)*
