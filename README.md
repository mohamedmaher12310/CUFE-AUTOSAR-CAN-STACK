


<div align="center">
  <h1> CUFE-AUTOSAR-COMMUNICATION-STACK</h1>
  
  ![Logo](https://github.com/user-attachments/assets/4e13fc55-d45e-4dff-83a0-c5f8e6e59cbe)

  <p>
   CAN Stack - AUTOSAR Layered Software Architecture V4.3.1 - Cairo University
  </p>

  
<!-- Badges -->
</div>

<br />

<!-- Table of Contents -->
# :notebook_with_decorative_cover: Table of Contents

- [About the Project](#star2-about-the-project)
  * [Layered AUTOSAR Architecture](📥Layered-AUTOSAR-Architecture)
  * [ASW](💻ASW)
  * [Implemented Modules](🎯Implemented-Modules)
- [Environment Variables](#key-environment-variables)
- [Contributing](#wave-contributing)
- [License](#warning-license)
- [Contact](#handshake-contact)
- [Acknowledgements](#gem-acknowledgements)
  

<!-- About the Project -->
## :star2: About the Project

This repository contains the implementation of a Communication Stack based on the AUTOSAR (AUTomotive Open System ARchitecture) Layered Software Architecture. The version used in this project is 4.3.1. This implementation was developed as part of a graduation project.
<div align="center"> 

  
  ![Modules](https://github.com/user-attachments/assets/b3f5c949-abe0-43bb-9e20-787d858499fd)



</div>


<!-- Layeres -->
### 📥 Layered AUTOSAR Architecture

<details>
  <summary>Basic Software (BSW) Layer</summary>
     
- Services Layer.
    
- ECU Abstraction Layer.

-  MCAL Layer.
    
</details>

<details>
  <summary>Run-Time Environment (RTE)</summary>
    
- Middleware layer providing communication services for AUTOSAR software components (SWC) and applications containing AUTOSAR sensor/actuator parts.
    
- Make AUTOSAR software components (SWC) independent of mapping to specific ECU.
</details>

<details>
<summary>Application Layer</summary>
</details>

<!-- ASW -->
### 💻 ASW

- The Communication Stack is our Graduation Project and is implemented using Embedded C.

<!--Implemented Modules -->
### 🎯  Implemented Modules

| Layer             | Module                                                             |
| ----------------- | ------------------------------------------------------------------ |
| Services Layer | [#COM Module](https://github.com/mohamedmaher12310/CUFE-AUTOSAR-CAN-STACK/tree/main/BSW/Service%20Layer/Com) - [#PDUR Module](https://github.com/mohamedmaher12310/CUFE-AUTOSAR-CAN-STACK/tree/main/BSW/Service%20Layer/PduR) - [#OS](https://github.com/mohamedmaher12310/CUFE-AUTOSAR-CAN-STACK/tree/main/BSW/Service%20Layer/Os) - [#Det](https://github.com/mohamedmaher12310/CUFE-AUTOSAR-CAN-STACK/tree/main/BSW/Service%20Layer/Det)|
| ECU Abstraction Layer | [#CANIF Module](https://github.com/mohamedmaher12310/CUFE-AUTOSAR-CAN-STACK/tree/main/BSW/ECUAL/CanIf)|
|  MCAL Layer | [#CAN Driver](https://github.com/mohamedmaher12310/CUFE-AUTOSAR-CAN-STACK/tree/main/BSW/MCAL/CanDrv)|

<!-- Env Variables -->
### :key: Environment Variables

To run this project, you will need to add the following environment variables to
- 3 Tiva C Series TM4C123G and read [Manual](https://www.ti.com/lit/pdf/spmu296)
- Read SWS AUTOSAR CP Release 4.3.1
   * [#CAN Driver](https://www.autosar.org/fileadmin/standards/R4-3/CP/AUTOSAR_SWS_CANDriver.pdf)
   * [#CANIF Module](https://www.autosar.org/fileadmin/standards/R4-3/CP/AUTOSAR_SWS_CANDriver.pdf)
   * [#PDUR Module](https://www.autosar.org/fileadmin/standards/R4-3/CP/AUTOSAR_SWS_PDURouter.pdf)
   * [#COM Module](https://www.autosar.org/fileadmin/standards/R4-3/CP/AUTOSAR_SWS_COMManager.pdf) 
- Understand the RX and TX Flow
<!-- Roadmap -->
## :compass: Roadmap
<div align="center"> 


![Project Roadmap](https://github.com/user-attachments/assets/afa93e5a-a432-4ceb-83ca-84d4a7dda661)


</div>

<!-- Contributing -->
## :wave: Contributing
Contributions to this project are welcome! 
If you find any issues or would like to suggest improvements, please open an issue or submit a pull request.

<!-- License -->
## :warning: License

Copyright © 2023, [Faculty of Engineering Ciro University](https://www.linkedin.com/in/omaranasr-ai/). Released under the [apache license v2.0](https://github.com/mohamedmaher12310/CUFE-AUTOSAR-CAN-STACK/blob/main/LICENSE).


<!-- Contact -->
## :handshake: Contact

- Project Supervisors
   - [Dr.Omar Nasr](https://www.linkedin.com/in/mohamed-abdelhay-727ab63a/) - omaranasr@cu.edu.eg
   - [Eng.Mohamed Abdelhay](https://www.linkedin.com/in/mohamed-abdelhay-727ab63a/) - mhmd.a.elhay@gmail.com
   - [Eng.Mohamed El-Khouly](https://www.linkedin.com/in/mohamed-el-khouly-70b05326/) - mohamed.elkhouly@brightskiesinc.com
- Team
  - [Omar Khedr](https://www.linkedin.com/in/omar-khedr-0a6559219/) - omaradelkhedr@gmail.com
  - [Omar Ahmed El-Shemy](https://www.linkedin.com/in/omar-el-shemy-463248235/) - omar.elshemy196@gmail.com
  - [Mohamed Maher Ahmed](https://www.linkedin.com/in/mohamed-maher-b58a8616b/) - Mohamedmaher12310@gmail.com
  - [Ahmed Abdelhamid Shokry](https://www.linkedin.com/in/ahmed-abdelhamid-b273b8240/) - asag99@gmail.com
  - [Nada Mohamed Moharram](https://www.linkedin.com/in/nada-mohamed-19164520a/) - nada.moharram1@gmail.com
  - [Shaimaa Mahmoud El-Saadi](https://www.linkedin.com/in/shaimaa-mahmoud-elsaadi-23690919b/) -shaimaaelsaadi@gmail.com

- Project Link: [https://github.com/mohamedmaher12310/CUFE-AUTOSAR-CAN-STACK](https://github.com/mohamedmaher12310/CUFE-AUTOSAR-CAN-STACK)

<!-- Acknowledgments -->
## :gem: Acknowledgements
We would like to acknowledge the following resources and references that helped in the development of this Communication Stack:
- [AUTOSAR Layered Software Architecture Specification](https://www.autosar.org/).
- Embedded C programming guides and best practices.
- CAN communication protocol specifications.
