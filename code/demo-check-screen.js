function checkScreen() {
    var screenWidth = window.screen.width;
    var mobileURL = "https://biolink-app-demo.netlify.app/";
    if (screenWidth <= 720) {
      window.location = mobileURL;
    }
  }
  
  window.onload = checkScreen;
  
