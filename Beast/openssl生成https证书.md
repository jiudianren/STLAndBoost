

# openssl、x509、crt、cer、key、csr、ssl、tls 这些都是什么鬼?
https://www.cnblogs.com/lan1x/p/5872915.html



# openssl生成证书
https://blog.csdn.net/m0_37886429/article/details/78549960

# 在服务器端创建证书
# 一、使用openssl生成CA证书

 在/tmp目录下新建一个ca文件夹，并在ca文件夹下创建四个子文件夹  
 
` export CA_HOME=/root/CA`
 
	[root@linux-node ~]# mkdir -p  $CA_HOME/{newcerts,private,conf,server} 
	[root@linux-node ~]# cd /tmp/ca/

	newcerts 目录用于存放CA签署过的数字证书。 
	private 目录用于存放CA的私钥。 
	conf 目录用于存放一些简化参数用的配置文件。 
	server 目录存放服务器证书文件。
	
	
# 二、在conf目录下新建一个包含如下信息的openssl.conf文件

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
	
	
# 三、生成私钥key文件

	[root@linux-node ~]# cd /tmp/ca
	[root@linux-node ca]# openssl genrsa -out $CA_HOME/private/ca.key
	
	
	
# 四、按提示输入所需信息，然后按回车键生成证书请求csr文件

	[root@linux-node ca]# openssl req -new -key $CA_HOME/private/ca.key -out $CA_HOME/private/ca.csr

备注： Common Name需要输入公司的域名。

示例：

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
	
实际：

	 一路空格，全空 ，设置为默认值
	 
	 
	 
	 
# 五、生成凭证crt文件

	[root@linux-node ca]# openssl x509 -req -days 365 -in $CA_HOME/private/ca.csr -signkey $CA_HOME/private/ca.key  -out $CA_HOME/private/ca.crt


	root@pcrf:~/CA# openssl x509 -req -days 365 -in $CA_HOME/private/ca.csr -signkey $CA_HOME/private/ca.key  -out $CA_HOME/private/ca.crt
	Signature ok
	subject=C = AU, ST = Some-State, O = Internet Widgits Pty Ltd
	Getting Private key


# 六、为CA的key设置起始序列号，可以是任意四个字符

	[root@linux-node ca]# echo FACE > $CA_HOME/serial

# 七、创建CA键库

	[root@linux-node ca]# touch $CA_HOME/index.txt

# 八、为移除客户端证书创建一个证书撤销列表

		
	1	touch /root/CA/index.txt.attr
	2 [root@linux-node ca]# openssl ca -gencrl -out $CA_HOME/private/ca.crl -crldays 7 -config "$CA_HOME/conf/openssl.conf"  Using configuration from $CA_HOME/conf/openssl.conf
	
	
	
	
	
	
	
# 为客户端证书签名
## 一、在ca目录内创建一个存放客户端key的目录users

[root@linux-node ca]# mkdir /tmp/ca/users
1
## 二、为客户端创建一个key

[root@linux-node ca]# openssl genrsa -des3 -out /tmp/ca/users/client.key 1024
1
备注： 创建key时要求输入pass phrase，这个是当前key的口令，以防止本密钥泄漏后被人盗用。两次输入同一个密码。

## 三、为客户端key创建一个证书签名请求csr文件

[root@linux-node ca]# openssl req -new -key /tmp/ca/users/client.key -out /tmp/ca/users/client.csr
1
输入该命令后，根据提示输入上一步输入的pass phrase，然后根据提示输入对应的信息 
备注： A challenge password是客户端证书口令。注意将它和client.key的口令进行区分。

## 四、使用CA证书的key为客户端key签名

[root@linux-node ca]# openssl ca -in /tmp/ca/users/client.csr -cert /tmp/ca/private/ca.crt \
-keyfile /tmp/ca/private/ca.key -out /tmp/ca/users/client.crt -config "/tmp/ca/conf/openssl.conf"
1
2
备注： 当出现确认是否签名的提示时，两次都输入y。

##  五、将证书转换为PKCS12文件

[root@linux-node ca]# openssl pkcs12 -export -clcerts -in /tmp/ca/users/client.crt \
-inkey /tmp/ca/users/client.key -out /tmp/ca/users/client.p12
1
2
按照提示输入客户端client.key的pass phrase。再输入用于导出证书的密码。这个是客户端证书的保护密码，在安装客户端证书时需要输入这个密码。

## 六、运行以下命令查看生成的客户端证书

[root@linux-node ca]# cd users
[root@linux-node users]# ls
client.crt  client.csr  client.key  client.p12