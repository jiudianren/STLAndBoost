

# openssl��x509��crt��cer��key��csr��ssl��tls ��Щ����ʲô��?
https://www.cnblogs.com/lan1x/p/5872915.html



# openssl����֤��
https://blog.csdn.net/m0_37886429/article/details/78549960

# �ڷ������˴���֤��
# һ��ʹ��openssl����CA֤��

 ��/tmpĿ¼���½�һ��ca�ļ��У�����ca�ļ����´����ĸ����ļ���  
 
` export CA_HOME=/root/CA`
 
	[root@linux-node ~]# mkdir -p  $CA_HOME/{newcerts,private,conf,server} 
	[root@linux-node ~]# cd /tmp/ca/

	newcerts Ŀ¼���ڴ��CAǩ���������֤�顣 
	private Ŀ¼���ڴ��CA��˽Կ�� 
	conf Ŀ¼���ڴ��һЩ�򻯲����õ������ļ��� 
	server Ŀ¼��ŷ�����֤���ļ���
	
	
# ������confĿ¼���½�һ������������Ϣ��openssl.conf�ļ�

	[ ca ]
	default_ca = foo
	[ foo ]
	dir =           $CA_HOME
	database =      $CA_HOME/index.txt
	new_certs_dir = $CA_HOME/newcerts
	certificate =   $CA_HOME/private/ca.crt
	serial =        $CA_HOME/serial
	private_key =   $CA_HOME/private/ca.key
	RANDFILE =      $CA_HOME/private/.rand
	default_days = 365
	default_crl_days= 30
	default_md = md5
	unique_subject = no
	policy = policy_any
	[ policy_any ]
	countryName = match
	stateOrProvinceName = match
	organizationName = match
	organizationalUnitName = match
	localityName = optional
	commonName      = supplied
	emailAddress    = optional
	
	
# ��������˽Կkey�ļ�

	[root@linux-node ~]# cd /tmp/ca
	[root@linux-node ca]# openssl genrsa -out $CA_HOME/private/ca.key
	
	
	
# �ġ�����ʾ����������Ϣ��Ȼ�󰴻س�������֤������csr�ļ�

	[root@linux-node ca]# openssl req -new -key $CA_HOME/private/ca.key -out $CA_HOME/private/ca.csr

��ע�� Common Name��Ҫ���빫˾��������

ʾ����

	root@pcrf:~/CA# openssl req -new -key $CA_HOME/private/ca.key -out $CA_HOME/private/ca.csr
	You are about to be asked to enter information that will be incorporated
	into your certificate request.
	What you are about to enter is what is called a Distinguished Name or a DN.
	There are quite a few fields but you can leave some blank
	For some fields there will be a default value,
	If you enter '.', the field will be left blank.
	-----
	Country Name (2 letter code) [AU]:CN                                                                                             
	State or Province Name (full name) [Some-State]:NJ
	Locality Name (eg, city) []:NJ
	Organization Name (eg, company) [Internet Widgits Pty Ltd]:jiudianren
	Organizational Unit Name (eg, section) []:jiudianren
	Common Name (e.g. server FQDN or YOUR name) []:jiudianren
	Email Address []:0027008978@iwhale.com
	
	Please enter the following 'extra' attributes
	to be sent with your certificate request
	A challenge password []:
	An optional company name []:
	root@pcrf:~/CA# 
	
ʵ�ʣ�

	 һ·�ո�ȫ�� ������ΪĬ��ֵ
	 
	 
	 
	 
# �塢����ƾ֤crt�ļ�

	[root@linux-node ca]# openssl x509 -req -days 365 -in $CA_HOME/private/ca.csr -signkey $CA_HOME/private/ca.key  -out $CA_HOME/private/ca.crt


	root@pcrf:~/CA# openssl x509 -req -days 365 -in $CA_HOME/private/ca.csr -signkey $CA_HOME/private/ca.key  -out $CA_HOME/private/ca.crt
	Signature ok
	subject=C = AU, ST = Some-State, O = Internet Widgits Pty Ltd
	Getting Private key


# ����ΪCA��key������ʼ���кţ������������ĸ��ַ�

	[root@linux-node ca]# echo FACE > $CA_HOME/serial

# �ߡ�����CA����

	[root@linux-node ca]# touch $CA_HOME/index.txt

# �ˡ�Ϊ�Ƴ��ͻ���֤�鴴��һ��֤�鳷���б�

		
	1	touch /root/CA/index.txt.attr
	2 [root@linux-node ca]# openssl ca -gencrl -out $CA_HOME/private/ca.crl -crldays 7 -config "$CA_HOME/conf/openssl.conf"  Using configuration from $CA_HOME/conf/openssl.conf
	
	
	
	
	
	
	
# Ϊ�ͻ���֤��ǩ��
## һ����caĿ¼�ڴ���һ����ſͻ���key��Ŀ¼users

[root@linux-node ca]# mkdir /tmp/ca/users
1
## ����Ϊ�ͻ��˴���һ��key

[root@linux-node ca]# openssl genrsa -des3 -out /tmp/ca/users/client.key 1024
1
��ע�� ����keyʱҪ������pass phrase������ǵ�ǰkey�Ŀ���Է�ֹ����Կй©���˵��á���������ͬһ�����롣

## ����Ϊ�ͻ���key����һ��֤��ǩ������csr�ļ�

[root@linux-node ca]# openssl req -new -key /tmp/ca/users/client.key -out /tmp/ca/users/client.csr
1
���������󣬸�����ʾ������һ�������pass phrase��Ȼ�������ʾ�����Ӧ����Ϣ 
��ע�� A challenge password�ǿͻ���֤����ע�⽫����client.key�Ŀ���������֡�

## �ġ�ʹ��CA֤���keyΪ�ͻ���keyǩ��

[root@linux-node ca]# openssl ca -in /tmp/ca/users/client.csr -cert /tmp/ca/private/ca.crt \
-keyfile /tmp/ca/private/ca.key -out /tmp/ca/users/client.crt -config "/tmp/ca/conf/openssl.conf"
1
2
��ע�� ������ȷ���Ƿ�ǩ������ʾʱ�����ζ�����y��

##  �塢��֤��ת��ΪPKCS12�ļ�

[root@linux-node ca]# openssl pkcs12 -export -clcerts -in /tmp/ca/users/client.crt \
-inkey /tmp/ca/users/client.key -out /tmp/ca/users/client.p12
1
2
������ʾ����ͻ���client.key��pass phrase�����������ڵ���֤������롣����ǿͻ���֤��ı������룬�ڰ�װ�ͻ���֤��ʱ��Ҫ����������롣

## ����������������鿴���ɵĿͻ���֤��

[root@linux-node ca]# cd users
[root@linux-node users]# ls
client.crt  client.csr  client.key  client.p12