# School project which maybe will implement a ftp server and qt client #
![http://ftpqt.googlecode.com/files/snímek5.png](http://ftpqt.googlecode.com/files/snímek5.png)
  * [see our changes list](https://code.google.com/p/ftpqt/source/list)
  * [our presentation (in Czech)](http://ftpqt.googlecode.com/files/y36api-FTPserver2.pdf)
## Current status ##
### client ###
  * recursive upload works
  * every upload transfer has own progressbar
  * multiple connections are uploading files

### server ###
currently implemented
  * ListenThread
  * ReqQueue
  * queueItem
  * partly data transfer
  * partly acceptionThread
![http://ftpqt.googlecode.com/files/snímek6.png](http://ftpqt.googlecode.com/files/snímek6.png)