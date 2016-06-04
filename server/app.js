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

// app.get('/', function(req, res) {
//   res.sendFile(__dirname + '/public/index.html');
// });

io.on('connection', function(socket) {
  console.log('DID A LAZY FOO JUST CONNECT?');
  socket.emit('message', 'This is a message from the dark side.');
});

server.listen(serverPort, function() {
  console.log('server up and running at %s port', serverPort);
});
