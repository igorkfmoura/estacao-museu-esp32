"<html>\
  <head>\
    <meta http-equiv='refresh' content='5'/>\
    <title>ESP32 Demo</title>\
    <style>\
      body { background-color: #cccccc; font-family: Arial, Helvetica, Sans-Serif; Color: #000088; }\
    </style>\
  </head>\
  <body>\
    <h1>Hello from ESP32!</h1>\
    <p>Uptime: %02d:%02d:%02d</p>\
    <p>temperature: %.02f °C</p>\
    <p>pressure: %.02f Pa</p>\
    <p>altitude %.02f m</p>\
  </body>\
  <script>\
    let options = {\
        method:'GET',\
    }\
  fetch('/getdata',options)\
  .then((response) => {\
      console.log(response);\
  });\
  </script>\
</html>"