


<div align="center">

  <img src="https://d9s1543upwp3n.cloudfront.net/wp-content/uploads/2023/04/AI-generated-car-design-scaled.jpeg" alt="logo" width="2580" height="400" />
  <h1> CUFE-AUTOSAR-COMMUNICATION-STACK</h1>
  
  <p>
   CAN Stack - AUTOSAR Layered Software Architecture V4.3.1 - Cairo University
  </p>

  
<!-- Badges -->

<h4>
    <a href="https://github.com/Louis3797/awesome-readme-template/">View Demo</a>
  <span> · </span>
    <a href="https://github.com/Louis3797/awesome-readme-template">Documentation</a>
  <span> · </span>
    <a href="https://github.com/mohamedmaher12310/CUFE-AUTOSAR-CAN-STACK/issues">Report Bug</a>
  <span> · </span>
    <a href="https://github.com/mohamedmaher12310/CUFE-AUTOSAR-CAN-STACK/issues">Request Feature</a>
  </h4>
</div>

<br />

<!-- Table of Contents -->
# :notebook_with_decorative_cover: Table of Contents

- [About the Project](#star2-about-the-project)
  * [Layered AUTOSAR Architecture](#stack-layeres )
  * [ASW](#ASW)
  * [Implemented Modules](#Modules)
- [Getting Started](#toolbox-getting-started)
  * [Prerequisites](#bangbang-prerequisites)
  * [Installation](#gear-installation)
  * [Run Locally](#running-run-locally)
- [Contributing](#wave-contributing)
  * [Code of Conduct](#scroll-code-of-conduct)
- [License](#warning-license)
- [Contact](#handshake-contact)
- [Acknowledgements](#gem-acknowledgements)
  

<!-- About the Project -->
## :star2: About the Project

This repository contains the implementation of a Communication Stack based on the AUTOSAR (AUTomotive Open System ARchitecture) Layered Software Architecture. The version used in this project is 4.3.1. This implementation was developed as part of a graduation project.
<div align="center"> 
  <img src="https://placehold.co/600x400?text=Your+Screenshot+here" alt="screenshot" />
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
| Services Layer | [#COM Module]()- [#PDUR Module]() |
| ECU Abstraction Layer | [#CANIF Module]()|
|  MCAL Layer | [#CAN Driver]()|

<!-- Env Variables -->
### :key: Environment Variables

To run this project, you will need to add the following environment variables to your .env file

`API_KEY`

`ANOTHER_API_KEY`

<!-- Getting Started -->
## 	:toolbox: Getting Started

<!-- Prerequisites -->
### :bangbang: Prerequisites

This project uses Yarn as a package manager

```bash
 npm install --global yarn
```

<!-- Installation -->
### :gear: Installation

Install my-project with npm

```bash
  yarn install my-project
  cd my-project
```


<!-- Run Locally -->
### :running: Run Locally

Clone the project

```bash
  git clone https://github.com/Louis3797/awesome-readme-template.git
```

Go to the project directory

```bash
  cd my-project
```

Install dependencies

```bash
  yarn install
```

Start the server

```bash
  yarn start
```


<!-- Usage -->
## :eyes: Usage

Use this space to tell a little more about your project and how it can be used. Show additional screenshots, code samples, demos or link to other resources.


```javascript
import Component from 'my-project'

function App() {
  return <Component />
}
```

<!-- Roadmap -->
## :compass: Roadmap

* [x] Todo 1
* [ ] Todo 2

<!-- Contributing -->
## :wave: Contributing
Contributions to this project are welcome! 
If you find any issues or would like to suggest improvements, please open an issue or submit a pull request.


<!-- Code of Conduct -->
### :scroll: Code of Conduct

Please read the [Code of Conduct](https://github.com/Louis3797/awesome-readme-template/blob/master/CODE_OF_CONDUCT.md)


<!-- License -->
## :warning: License

Copyright © 2023, [Faculty of Engineering Ciro University](https://www.linkedin.com/in/omaranasr-ai/). Released under the [apache license v2.0](https://github.com/mohamedmaher12310/CUFE-AUTOSAR-CAN-STACK/blob/main/LICENSE).


<!-- Contact -->
## :handshake: Contact

- Project Supervisors
   - [Dr.Omar Nasr](https://www.linkedin.com/in/mohamed-abdelhay-727ab63a/) - mhmd.a.elhay@gmail.com
   - [Eng.Mohamed Abdelhay](https://www.linkedin.com/in/mohamed-abdelhay-727ab63a/) - mhmd.a.elhay@gmail.com
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
