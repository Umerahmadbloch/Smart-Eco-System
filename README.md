# IoT-Based Saffron Cultivation System in Greenhouse

A reference implementation and documentation resource inspired by the paper:

> **Internet of Things (IoT) based saffron cultivation system in greenhouse**
> *Scientific Reports*, volume 14, Article number: 22589 (2024)
> https://www.nature.com/articles/s41598-024-69513-1

---

## About the Paper

Saffron is the world's most expensive and environment-sensitive crop. Its global
cultivation has declined sharply due to factors that traditional open-field
farming cannot control: rapid climate change, erratic temperature variations,
fluctuating light intensity, soil moisture imbalance, salinity, pH changes, and
unpredictable water availability.

This paper proposes an IoT-based greenhouse system that automatically monitors
and controls these agronomical variables, delivering real-time data to the farm
owner through a mobile/web dashboard (Blynk IoT).

---

## System Architecture

The system uses a **four-layer IoT architecture**:

| Layer | Responsibility |
|-------|----------------|
| **Perception layer** | Sensors, microcontroller, and actuators that collect real-world data |
| **Network layer** | Networking technologies that transmit sensed data between layers |
| **Service layer** | Analysis and processing; compares sensed values against cloud-stored thresholds |
| **Application layer** | Blynk IoT mobile/web dashboard for farmer monitoring and control |

---

## Agronomical Variables Controlled

| Variable | Sensor Used | Optimal Range |
|----------|-------------|---------------|
| Temperature | DHT-11 | ~20-30 °C |
| Humidity | DHT-11 | per saffron needs |
| Soil moisture | Sentek EnviroSCAN | per growth stage |
| Soil salinity | Sentek EnviroSCAN (EC) | per salinity tolerance |
| pH level | pH 2.0 Interface | 6.0-7.0 |
| Light intensity | LDR | 150-200 µmol m⁻² s⁻¹ |
| Corm size/weight | Load cell | > 8 g |

---

## Hardware Used

- **Microcontroller:** Arduino Nano 33 IoT (Wi-Fi + Bluetooth, 256 kB flash, 32 kB SRAM, 3.3 V)
- **Sensors:** DHT-11, Sentek EnviroSCAN, pH 2.0 Interface, LDR, load cell
- **Actuators:** Water pump, cooling fans, exhaust fan, LED artificial lights
- **Connectivity:** Mobile broadband internet for reliable real-time cloud sync
- **Dashboard:** Blynk IoT app with single-admin authentication and verification code

---

## Operational Logic

1. Sensors sample environmental variables at short intervals.
2. Microcontroller compares sensed values with cloud-stored thresholds.
3. Actuators trigger automatically when values deviate:

   | Condition | Action |
   |-----------|--------|
   | Temperature high | Fan on |
   | Humidity high | Exhaust fan on |
   | Light low | LED lights on |
   | Moisture low | Water pump on |
   | pH out of range | Alert + corrective action |

4. Real-time data and alerts are pushed to the Blynk IoT app.
5. Farmer can monitor and intervene manually from phone/tablet/laptop.

---

## Experimental Setup

- Conducted in **June 2023** under extreme weather conditions
- **Soil:** Loamy soil (sand + clay + silt), pH 6-7.5, good drainage
- **Planting:** Saffron corms at 10-15 cm depth, 10 cm spacing
- **Sensor placement:**
  - Ground sensors at 30-40 cm depth
  - Environmental sensors at 40-50 cm above canopy
  - Load cell outside farming area to avoid interference
- **Power backup:** 18 V adapter with battery backup

---

## Results

The paper reports that the proposed system successfully:

- Maximized saffron production in the greenhouse by maintaining optimal conditions
- Automated real-time monitoring and control of all critical agronomical variables
- Reduced labor costs and improved resource efficiency
- Provided remote access to farm data via Blynk IoT
- Achieved reliable operation under power outage and communication failure scenarios

---

## Fault Handling Strategies

- Continuous monitoring with null/NaN detection
- Unique device IDs for fast fault identification
- SMS alerts on anomalies
- Modular hardware for quick replacement
- Retry mechanism for communication failures
- Sensor calibration with ±5/0.5 tolerance

---

## Scalability and Adaptability

- **Modular design** allows expansion or reduction based on greenhouse size
- **Interoperability** with existing agricultural management systems
- **Adjustable parameters** based on real-time data and crop needs

---

## Reported Novelty

According to the authors, this is the **first IoT-based system focused on
soil-based greenhouse saffron cultivation** that monitors and controls the most
critical agronomical factors affecting saffron growth, which cannot be managed
in traditional open-field farming.

---

## Future Work Mentioned in Paper

- Integration of **machine learning and AI** for predictive analytics
- **Pest detection and control** systems
- **Advanced sensors** for granular microclimate monitoring
- **Predictive maintenance** of hardware using ML classifiers

---

## Dataset

The dataset is publicly available at:

https://github.com/RabiaKhan-94/ECOFARMING

---

## Citation

If you use this work or the referenced paper, please cite:

```bibtex
@article{Khan2024SaffronIoT,
  title   = {Internet of things (IoT) based saffron cultivation system in greenhouse},
  author  = {Khan, Rabia and others},
  journal = {Scientific Reports},
  volume  = {14},
  number  = {22589},
  year    = {2024},
  doi     = {10.1038/s41598-024-69513-1},
  url     = {https://www.nature.com/articles/s41598-024-69513-1}
}
