//==============================================
// Copyright 2022. Daero All rights reserved.
// Do not copy, modify, or distribute goods without permission.
//==============================================

1) VS2022(v143), std::C++20, x64(Debug, Release)

2) ���� ���̺귯��

- NetProtobuf.lib : ��Ŷ, ������ ����(*.proto), ��������� �ø��������
- NetCommonLib.lib : ����, Ŭ���̾�Ʈ ���� ���
- NetClientLib.lib : Ŭ���̾�Ʈ �ھ�
- NetServerLib.lib : ���� �ھ� (NetClientLib�� �����ؼ� LanClient�� ����, ����)

3) �ܺ� ���̺귯��

- JsonCPpp.Windows.1.9.2
- Protobuf 3

## Server
- NetServerLib.lib ���� �ν��Ͻ� ���� (CServer)
- NetCommonLib�� ��Ʈ��ũ �̺�Ʈ �ڵ鷯�� ��ӹ޾Ƽ� ��� ����, ���� �ν��Ͻ��� ���.
- NetCommonLib�� ��Ŷ �̺�Ʈ �ڵ鷯�� ��ӹ޾Ƽ� ��� ����, ���� �ν��Ͻ��� ���.
- NetServerLib�� ��׶��� ��ũ�� ��ӹ޾Ƽ� ��� ����, ���� �ν��Ͻ��� ���.
- NetServerLib�� ���� ������ ��ӹ޾Ƽ� ��� ����, ���� �ν��Ͻ��� ���. (����� json���� �۾���)
- Ŭ���̾�Ʈ ���� ����
- NetClientLib.lib�� Ŭ���̾�Ʈ ����� ����� Lan Client ���
- ��Ŷ �ø��������, ��ø�������� (��������� ����)
- 

## Client
- NetClientLib.lib Ŭ���̾�Ʈ �ν��Ͻ� ���� (CClient)
- NetCommonLib�� ��Ʈ��ũ �̺�Ʈ �ڵ鷯�� ��ӹ޾Ƽ� ��� ����, Ŭ���̾�Ʈ �ν��Ͻ��� ���.
- NetCommonLib�� ��Ŷ �̺�Ʈ �ڵ鷯�� ��ӹ޾Ƽ� ��� ����, Ŭ���̾�Ʈ �ν��Ͻ��� ���.
