# gcc 및 util 설치
```
$ sudo apt-get install gcc g++ cmake pkg-config curl zip unzip tar libutf8proc-dev  
```

# vcpkg 준비
```
$ pwd 
/home/user
$ git clone https://github.com/microsoft/vcpkg.git
$ cd vcpkg && ./bootstrap-vcpkg.sh
$ pwd 
/home/user/vcpkg
$ export VCPKG_ROOT=$(pwd)
$ export PATH=$VCPKG_ROOT:$PATH
```

# 프로젝트 준비
vcpkg에 c++ library 패키지를 추가하기 위해서는 `vcpkg add port <패키지명>` 명령을 사용
* `vcpkg new --application`
* `vcpkg add port <패키지명>`
```
$ mkdir helloworld && cd helloworld
$ vcpkg new --application
$ vcpkg add port fmt poco
```

# CMakeList 생성
```
$ vi CMakeLists.txt
$ vi CMakePresets.json
$ vi CMakeUserPresets.json
```

# 빌드
```
$ cmake --preset=default
$ cmake --build build
```