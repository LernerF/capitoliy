# Отчет по работе с SSH ключами
## по курсу "Фундаментальная информатика"

Студент группы <M8O-108Б-23> Лернер Феликс Леонидович 

Преподаватель: каф. 806 Севастьянов Виктор Сергеевич

**Тема:** Работа с SSH ключами

**Цель работы:** Ознакомиться с принципами работы и использования SSH ключей для безопасного удаленного доступа к серверам.

**Задание:** Создать и настроить SSH ключи для авторизации на удаленных серверах.

**Идея, метод, алгоритм решения задачи:** Для выполнения данной работы необходимо выполнить следующие шаги:

1 этап.
      Установить OpenSSH на локальную машину.
2 этап. 
      Сгенерировать SSH ключи с помощью команды ssh-keygen.
3 этап. 
      Скопировать публичный ключ на удаленный сервер с помощью команды ssh-copy-id.
4 этап. 
      Проверить возможность авторизации на удаленном сервере с использованием SSH ключей.

**Сценарий выполнения работы:**
1. Установка OpenSSH:
   - Открываем терминал на локальной машине.
   - Выполняем команду sudo apt-get install openssh-server для установки OpenSSH.
   
2. Генерация SSH ключей:
   - В терминале выполняем команду ssh-keygen.
   - Указываем путь и имя файла для сохранения ключей.
   - Вводим пароль (по желанию).
   - Генерация ключей будет завершена.
   
3. Копирование публичного ключа на удаленный сервер:
   - В терминале выполняем команду ssh-copy-id <username>@<remote_host>.
   - Вводим пароль пользователя на удаленном сервере.
   - Публичный ключ будет скопирован на удаленный сервер.
   
4. Проверка авторизации с использованием SSH ключей:
   - В терминале выполняем команду ssh <username>@<remote_host>.
   - Если все настройки выполнены правильно, то авторизация будет успешной.

В результате выполнения работы были успешно созданы и настроены SSH ключи для авторизации на удаленных серверах. Теперь можно использовать SSH ключи для безопасного удаленного доступа к серверам.




```
f_lerner@LAPTOP-L659LAFN:~$ ssh-keygen 
Generating public/private rsa key pair.                                                                                 
Enter file in which to save the key (/home/f_lerner/.ssh/id_rsa):                                                       
Created directory '/home/f_lerner/.ssh'.Enter passphrase (empty for no passphrase):                          
Enter same passphrase again:                                                                                           
Your identification has been saved in /home/f_lerner/.ssh/id_rsa                                                       
Your public key has been saved in /home/f_lerner/.ssh/id_rsa.pub                                                        
The key fingerprint is:                                                                                                 
SHA256:n3BRyGcVmLAcaliLZuuJ0K1/CebU4pehHrqYGzcosbA f_lerner@LAPTOP-L659LAFN                                             
The key's randomart image is: +---[RSA 3072]----+                                                                                                     
|        ..oo.+o. |                                                                                                     
|       + +o+=    |                                                                                                     
|      = + +o     |                                                                                                     
|   . + o   .     |                                                                                                     
|o . . o.S .      |                                                                                                     
|.+ o +=.o+ .     |                                                                                                     
|E o ==++ +o      |                                                                                                     
| . = ++.=        |                                                                                                     
|  +.oooo         |                                                                                                     
+----[SHA256]-----+                                                                                                     
f_lerner@LAPTOP-L659LAFN:~$ ssh copy-id                                                                                 
ssh: Could not resolve hostname copy-id: Name or service not known                                                     
f_lerner@LAPTOP-L659LAFN:~$ ssh copy-id f-lerner@185.5.249.140                                                          
ssh: Could not resolve hostname copy-id: Name or service not known                                                      
f_lerner@LAPTOP-L659LAFN:~$ ssh copy-id f_lerner@185.5.249.140                                                          
ssh: Could not resolve hostname copy-id: Name or service not known                                                      
f_lerner@LAPTOP-L659LAFN:~$ pwd                                                                                         
f_lerner@LAPTOP-L659LAFN:~$ ssh copy-id ~/.ssh/id_rsa.pub f_lerner@185.5.249.140                                        
ssh: Could not resolve hostname copy-id: Name or service not known                                                      
f_lerner@LAPTOP-L659LAFN:~$ ssh f_lerner@185.5.249.140                                                                  
The authenticity of host '185.5.249.140 (185.5.249.140)' can't be established.                                          
ED25519 key fingerprint is SHA256:gMWpghci4jH+8KckY83J+zLNE4DrwfrDZorZZU2IRGI.                                          
This key is not known by any other names                                                                                
Are you sure you want to continue connecting (yes/no/[fingerprint])? yes                                                
Warning: Permanently added '185.5.249.140' (ED25519) to the list of known hosts.                                        
f_lerner@185.5.249.140's password:                                                                                      
Permission denied, please try again.                                                                                                                        
Welcome to Ubuntu 20.04.6 LTS (GNU/Linux 5.4.0-162-generic x86_64)                                                                                                                                          * Documentation:  https://help.ubuntu.com                                                                               
* Management:     https://landscape.canonical.com
* * Support:        https://ubuntu.com/advantage
  * New release '22.04.3 LTS' available.
  * Run 'do-release-upgrade' to upgrade to it.                                                                                                                                                               Last login: Fri Sep 29 17:13:46 2023 from 91.193.177.45
  * f_lerner@vds2476450:~$ mkdir .ssh
  * f_lerner@vds2476450:~$ touch .ssh/authorized_keys
  * f_lerner@vds2476450:~$ logout
  * Connection to 185.5.249.140 closed.
  * f_lerner@LAPTOP-L659LAFN:~$ scp .ssh/id_rsa
  * .ssh/id_rsa       .ssh/id_rsa.pub```
  *
  *
  *
  * f_lerner@LAPTOP-L659LAFN:~$ scp .ssh/id_rsa.pub f_lerner@185.249.140:~
  * ^Cf_lerner@LAPTOP-L659LAFN:~$ scp .ssh/id_rsa.pub f_lerner@185.249.140:~                                                                                                                                    ^Cf_lerner@LAPTOP-L659LAFN:~$ cat ~/.ssh/id_rsa.pub f_lerner@185.249.140:~
  * ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABgQC35skPbwlYsgVH6m2zBuxkawD5NIK8EDqJwF4BdMpGmMr27bDNZrQ+5f9TOITQkyl/0fGtp1YFQRlqIL2EIHO9XIvLyInlEYdQRCosk4SoOkPJ9wvoMdsUHSh+cGVXF8DsOm7uCPBtfQ7iXtpTJ240p5uPYEBpDv+31JeRc8oy+4jfF6T6AwhMZoOR8RId/lBaQtOevGQuFc7FUBLeSCIYG538A6UGwuWbZEtMn/014O4o/aqUU6HkGqfySQlJIHkHQhjvfdf2Bq4AtsfPCd1lQ2DFG3L6NSK3i47Y1ojmD9wJY13fqRf7buIg7nzEivbvy2tQAgi6Gugg70pb00DSpJargecpGyDPsv2fsyFn5C1WoLcDrHGSRh4fH8QGHIqd7r6KaNrkD/RGx7jsGAo1YoU5oT4up//MJYVCnkbuhxNrbiZ1mlYmlf1hSDUKEZATJyLjK32J4WwWbw+yugrIreE9XrvDguamV1+gEGxmk6HC/Gg70ikKitVPdOq9ygE= f_lerner@LAPTOP-L659LAFN
  * cat: 'f_lerner@185.249.140:~':
  * No such file or directory
  * f_lerner@LAPTOP-L659LAFN:~$ scp .ssh/id_rsa.pub f_lerner@185.5.249.140:~
  *
  * f_lerner@185.5.249.140's password:
  *  Permission denied, please try again.
  *   f_lerner@185.5.249.140's password:                                                                                                                                                                
       100%  578    13.1KB/s   00:00
  *   f_lerner@LAPTOP-L659LAFN:~$ history | grep ssh
  * 4  ssh-keygen
  * 5  ssh copy-id
    6  ssh copy-id f-lerner@185.5.249.140
    7  ssh copy-id f_lerner@185.5.249.140
    9  ls .ssh
    10  ssh copy-id ~/.ssh/id_rsa.pub f_lerner@185.5.249.140
    11  ssh f_lerner@185.5.249.140
    12  scp .ssh/id_rsa.pub f_lerner@185.249.140:~
    14  scp .ssh/id_rsa.pub f_lerner@185.5.249.140:~
    15  history | grep ssh
    f_lerner@LAPTOP-L659LAFN:~$ history 11
    6  ssh copy-id f-lerner@185.5.249.140
    7  ssh copy-id f_lerner@185.5.249.140
    8  pwd
    9  ls .ssh
    10  ssh copy-id ~/.ssh/id_rsa.pub f_lerner@185.5.249.140
    11  ssh f_lerner@185.5.249.140
    12  scp .ssh/id_rsa.pub f_lerner@185.249.140:~
    13*
    14  scp .ssh/id_rsa.pub f_lerner@185.5.249.140:~
    15  history | grep ssh
    16  history 11
    f_lerner@LAPTOP-L659LAFN:~$ ssh f_lerner@185.5.249.140
    f_lerner@185.5.249.140's password:
    Permission denied, please try again.
    f_lerner@185.5.249.140's password:
    Welcome to Ubuntu 20.04.6 LTS (GNU/Linux 5.4.0-162-generic x86_64)                                                                                                                                          * Documentation:  https://help.ubuntu.com
    * Management:     https://landscape.canonical.com
    * * Support:        https://ubuntu.com/advantage
      * New release '22.04.3 LTS' available.
      *  Run 'do-release-upgrade' to upgrade to it.                                                                                                                                                        Last login: Fri Sep 29 17:46:39 2023 from 91.193.177.45
      *  f_lerner@vds2476450:~$ ls
      *   id_rsa.pub
      *
      *   f_lerner@vds2476450:~$ ls -l
      *   total 4
      *   -rw-r--r-- 1 f_lerner f_lerner 578 Sep 29 17:56 id_rsa.pub
      *   f_lerner@vds2476450:~$ ls -a
      *
      *   .  ..  .bash_history  .bash_logout  .bashrc  .cache  id_rsa.pub  .profile  .ssh
      *    f_lerner@vds2476450:~$ cat id_rsa.pub >> .ssh/authorized_keys
      *    f_lerner@vds2476450:~$ cd .ssh
      *    f_lerner@vds2476450:~/.ssh$ ls
           autoohorized_keys
           f_lerner@vds2476450:~/.ssh$ cat authorized_keys
           ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABgQC35skPbwlYsgVH6m2zBuxkawD5NIK8EDqJwF4BdMpGmMr27bDNZrQ+5f9TOITQkyl/0fGtp1YFQRlqIL2EIHO9XIvLyInlEYdQRCosk4SoOkPJ9wvoMdsUHSh+cGVXF8DsOm7uCPBtfQ7iXtpTJ240p5uPYEBpDv+31JeRc8oy+4jfF6T6AwhMZoOR8RId/lBaQtOevGQuFc7FUBLeSCIYG538A6UGwuWbZEtMn/014O4o/aqUU6HkGqfySQlJIHkHQhjvfdf2Bq4AtsfPCd1lQ2DFG3L6NSK3i47Y1ojmD9wJY13fqRf7buIg7nzEivbvy2tQAgi6Gugg70pb00DSpJargecpGyDPsv2fsyFn5C1WoLcDrHGSRh4fH8QGHIqd7r6KaNrkD/RGx7jsGAo1YoU5oT4up//MJYVCnkbuhxNrbiZ1mlYmlf1hSDUKEZATJyLjK32J4WwWbw+yugrIreE9XrvDguamV1+gEGxmk6HC/Gg70ikKitVPdOq9ygE= f_lerner@LAPTOP-L659LAFN                       f_lerner@vds2476450:~/.ssh$ logout                                                                                      Connection to 185.5.249.140 closed.

           f_lerner@LAPTOP-L659LAFN:~$ ssh f_lerner@185.5.249.140
            Welcome to Ubuntu 20.04.6 LTS (GNU/Linux 5.4.0-162-generic x86_64)
           * Documentation:  https://help.ubuntu.com
           * * Management:     https://landscape.canonical.com
           * * Support:      https://ubuntu.com/advantage
             *  New release '22.04.3 LTS' available.
             *   Run 'do-release-upgrade' to upgrade to it.                                                                                                                                                            Last login: Fri Sep 29 17:59:49 2023 from 91.193.177.45
             *   f_lerner@vds2476450:~$ vim
             *    Could not find command-not-found database. Run 'sudo apt update' to populate it.
             *  мvim: command not found
             *  f_lerner@vds2476450:~$ vi
             *  f_lerner@vds2476450:~$ vi /etc/host
             *  host.conf    hostname     hosts        hosts.allow  hosts.deny
             *  f_lerner@vds2476450:~$ vi /etc/host
             *  host.conf    hostname     hosts        hosts.allow  hosts.deny
             *  f_lerner@vds2476450:~$ vi /etc/hosts
             *  f_lerner@vds2476450:~$ sudo !! 
/home/f_lerner                                                                                                          
f_lerner@LAPTOP-L659LAFN:~$ ls .ssh                                                                                     
id_rsa  id_rsa.pub                                                                                                      
```
**7 этап**. Зачемачний нет.

**8 этап** Работа была очень интерсеной, благодаря данной ЛБ я научился удаленно подключатся к серверам, а также стал намного лучше разбираться в командной строке,
в будущем уверен, что данное умение мне обязательно пригодится, ведь данная тема весьма актулаьна

