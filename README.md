## RoNet

Copyright 2022-2024. Daero All rights reserved.
Do not copy, modify, or distribute goods without permission.

### Dev
VS2022(v143), std::C++20, x64(Debug, Release)

### Library
| Name             | Desc                                             |
| :--------------- |:-------------------------------------------------|
| NetProtobuf.lib  | 패킷, 프로토 파일(*.proto), 프로토버프 시리얼라이저 |
| NetCommonLib.lib | 서버, 클라이언트 공용 기능 |
| NetClientLib.lib | 클라이언트 코어 |
| NetServerLib.lib | 서버 코어 (NetClientLib를 참조해서 LanClient를 생성, 관리) |
| JsonCpp.Windows | v1.9.2 |
| Protobuf3        | Google ProtoBuffer |

### Server
- NetServerLib.lib 서버 인스턴스 생성 (CServer)
  - NetCommonLib의 네트워크 이벤트 핸들러를 상속받아서 기능 정의, 서버 인스턴스에 등록.
  - NetCommonLib의 패킷 이벤트 핸들러를 상속받아서 기능 정의, 서버 인스턴스에 등록.
  - NetServerLib의 백그라운드 워크를 상속받아서 기능 정의, 서버 인스턴스에 등록.
  - NetServerLib의 서버 설정을 상속받아서 기능 정의, 서버 인스턴스에 등록. (현재는 json으로 작업됨)
- 클라이언트 세션 관리
- NetClientLib.lib의 클라이언트 기능을 사용한 Lan Client 기능
- 패킷 시리얼라이즈, 디시리얼라이즈 (프로토버프 적용)

### Client
- NetClientLib.lib 클라이언트 인스턴스 생성 (CClient)
  - NetCommonLib의 네트워크 이벤트 핸들러를 상속받아서 기능 정의, 클라이언트 인스턴스에 등록.
  - NetCommonLib의 패킷 이벤트 핸들러를 상속받아서 기능 정의, 클라이언트 인스턴스에 등록.
