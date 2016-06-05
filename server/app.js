var fs = require('fs');
var https = require('https');
var express = require('express');
var app = express();

var options = {
  key: fs.readFileSync('./file.pem'),
  cert: fs.readFileSync('./file.crt')
};

var serverPort = 3000;

var server = https.createServer(options, app);
var io = require('socket.io')(server);

io.on('connection', function(socket) {

  console.log('DID A LAZY FOO JUST CONNECT?');
  socket.emit('message', { message: 'HELLO FROM SERVER!'});

  socket.on('update frame', function(data) {
    console.log(data);
  });

});

server.listen(serverPort, function() {
  console.log('server up and running at %s port', serverPort);
});
