<!-- Improved compatibility of back to top link: See: https://github.com/othneildrew/Best-README-Template/pull/73 -->

<a name="readme-top"></a>

[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]

<!-- PROJECT LOGO *not sure if I can use the actuial logo in my project for legal reasons-->
<br />
<div align="center">
  <a href="https://github.com/KaraboMolemane/homes-app-start">
    <img src="" alt="Vehicle_Position_Powerfleet_Logo" width="80" height="80">
  </a>

<h3 align="center">Vehicle Position Powerfleet</h3>
  <p align="center">
    This is task for <a href="https://[angular.dev/tutorials/first-app">Powerfleet</a>. You have a dataset containing 2 million vehicle position entries (stored in a binary file), each representing a vehicle's latitude and longitude around the world. In addition, you are given 10 predefined locations. The challenge here is to efficiently process this large dataset and find the closest vehicles to each of the provided locations.  
    <br />  
    <br />  
    See more specific about the <a href="https://github.com/MiXTelematics/Recruitment">task</a> in the original <a href="https://github.com/MiXTelematics/Recruitment/blob/master/VehiclePositions/Instructions%20for%20Firmware%20Candidates/README.md">README.md</a> or <a href="https://github.com/KaraboMolemane/vehicle-positions-powerfleet/blob/master/README.md">here</a>.
    <br />
    <a href="https://github.com/KaraboMolemane/homes-app-start"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/KaraboMolemane/homes-app-start">View Demo</a>
    ·
    <a href="https://github.com/KaraboMolemane/homes-app-start/issues">Report Bug</a>
    ·
    <a href="https://github.com/KaraboMolemane/homes-app-start/issues">Request Feature</a>
  </p>
</div>

<!-- ABOUT THE PROJECT -->

## About The Project

<p align="right">(<a href="#readme-top">back to top</a>)</p>

### Built With

- [C language](https://www.mingw-w64.org/)

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- GETTING STARTED -->

## Getting Started

### Prerequisites

Below is a list of things you need to use the project and how to install them.

- GCC compiler toolchain (recommend [MinGW](https://sourceforge.net/projects/mingw/)/MSYS for Windows users)

> [!NOTE]
> The instructions below are for a Windows machine.

### Installation

- Fork the repo
  - Go to the repository page: https://github.com/KaraboMolemane/vehicle-positions-powerfleet
  - Click the “Fork” button at the top right of the page to create a personal copy of the repository on your GitHub account.
- Clone the repo

  ```sh
  git clone https://github.com/<your-username>/<new-repo-name>.git

  ```

- Extract the data file

  - Exctract
    ```sh
    ../vehicle-positions-powerfleet/VehiclePositions/VehiclePositions_DataFile.zip
    ```
  - To
    ```sh
    ../vehicle-positions-powerfleet/VehiclePositions/VehiclePositions_DataFile/VehiclePositions.dat
    ```

- Build the `solution.exe`
  - Open `command prompt` and navigate to the location below
    ```sh
    cd ../vehicle-positions-powerfleet/VehiclePositions/Instructions for Firmware Candidates/
    ```
  - Run one of the commands below to have the `makefile` compile the `solution.exe`
    ```sh
    make
    ```
    OR 
    ```sh
    mingw32-make
    ```

- Execute the `solution.exe`
  - To run the program, run the command below in the same  `command prompt`  instance
    ```sh
    solution.exe
    ```

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- USAGE EXAMPLES -->

## Usage

Once the project executed, it will output the results as shown below.

<div align="center">
    <img src="VehiclePositions/Instructions for Firmware Candidates/Results.png" alt="Results" width="650" height="250" >
</div>

_For more examples, please refer to the [Documentation](https://example.com)_

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- ROADMAP -->

## Roadmap

- Below are some perfromance comments by Powerfleet 
  - Your solution should find the position IDs in under 500ms when run on our benchmark PC: 1.9GHz, Turbo 4.8Ghz, 4 Cores, 8 Threads
  - A basic optimized version using the benchmark approach is expected to run in under 400ms.
  - A further optimized approach that e.g. focuses on maximum CPU utilization is expected to run in under 200ms.
  - The current record for finding all position IDs on our benchmarking PC is 29 ms.
- A goal for the near future is to further optimise the code to first achieve running under 200ms
- In the longer term I would like to optimize the code to get closer to the 29ms mark as a BHAG (A Big Hairy Audacious Goal) 
- Below are some of my benchmarking results with the current code:
  
| Spec | Avarage execution time | Comment |
|----------|----------|----------|
| Processor	13th Gen Intel(R) Core(TM) i7-1355U, 1700 Mhz, 10 Core(s), 12 Logical Processor(s) | 351ms | Main dev machine |
| Intel(R) Core(TM) i5-8250U CPU @ 1.6GHz, 1800Mhz 4 Core(s), 8 Logical Processor(s) | 390ms |  |
| Processor	Intel(R) Celeron(R) N4000 CPU @ 1.10GHz, 1101 Mhz, 2 Core(s), 2 Logical Processor(s) | 945ms |  |


See the [open issues](https://github.com/KaraboMolemane/vehicle-positions-powerfleet/issues) for a full list of proposed features (and known issues).

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- CONTRIBUTING -->

## Contributing

Contributions are what make the open source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement".
Don't forget to give the project a star! Thanks again!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- LICENSE -->

## License

N/A

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- CONTACT -->

## Contact

Karabo Molemane - https://www.linkedin.com/in/karabo-molemane/

Project Link: [https://github.com/KaraboMolemane/homes-app-start](https://github.com/KaraboMolemane/homes-app-start)

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- ACKNOWLEDGMENTS -->

## Acknowledgments

- [Othneil Drew](https://github.com/othneildrew/Best-README-Template)

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->

[contributors-shield]: https://img.shields.io/github/contributors/KaraboMolemane/authentication-manager.svg?style=for-the-badge
[contributors-url]: https://github.com/KaraboMolemane/maintenance-management/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/KaraboMolemane/authentication-manager.svg?style=for-the-badge
[forks-url]: https://github.com/KaraboMolemane/maintenance-management/network/members
[stars-shield]: https://img.shields.io/github/stars/KaraboMolemane/authentication-manager.svg?style=for-the-badge
[stars-url]: https://github.com/KaraboMolemane/maintenance-management/stargazers
[issues-shield]: https://img.shields.io/github/issues/KaraboMolemane/authentication-manager.svg?style=for-the-badge
[issues-url]: https://github.com/KaraboMolemane/maintenance-management/issues
[license-shield]: https://img.shields.io/github/license/KaraboMolemane/authentication-manager.svg?style=for-the-badge
[license-url]: https://github.com/KaraboMolemane/maintenance-management/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://www.linkedin.com/in/karabo-molemane/
[product-screenshot]: images/screenshot.png
[Next.js]: https://img.shields.io/badge/next.js-000000?style=for-the-badge&logo=nextdotjs&logoColor=white
[Next-url]: https://nextjs.org/
[React.js]: https://img.shields.io/badge/React-20232A?style=for-the-badge&logo=react&logoColor=61DAFB
[React-url]: https://reactjs.org/
[Vue.js]: https://img.shields.io/badge/Vue.js-35495E?style=for-the-badge&logo=vuedotjs&logoColor=4FC08D
[Vue-url]: https://vuejs.org/
[Angular.io]: https://img.shields.io/badge/Angular-DD0031?style=for-the-badge&logo=angular&logoColor=white
[Angular-url]: https://angular.io/
[Svelte.dev]: https://img.shields.io/badge/Svelte-4A4A55?style=for-the-badge&logo=svelte&logoColor=FF3E00
[Svelte-url]: https://svelte.dev/
[Laravel.com]: https://img.shields.io/badge/Laravel-FF2D20?style=for-the-badge&logo=laravel&logoColor=white
[Laravel-url]: https://laravel.com
[Bootstrap.com]: https://img.shields.io/badge/Bootstrap-563D7C?style=for-the-badge&logo=bootstrap&logoColor=white
[Bootstrap-url]: https://getbootstrap.com
[JQuery.com]: https://img.shields.io/badge/jQuery-0769AD?style=for-the-badge&logo=jquery&logoColor=white
[JQuery-url]: https://jquery.com
[expressjs.com]: https://img.shields.io/badge/Express-999D7C?style=for-the-badge&logo=express&logoColor=white
[Express-url]: https://expressjs.com
[js.devexpress.com]: https://img.shields.io/badge/DevExpress-1999AD?style=for-the-badge&logo=devexpress&logoColor=white
[devexpress-url]: https://js.devexpress.com
