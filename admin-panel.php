<!----------------------------------------------------------------------------------------------------

The following document is owned by:
@sevinATEnine (and alt) @Cesium72 @tacocat15 and @cmsmith02

It is under the Creative Commons license and may not be reproduced commercially or without
direct permission from the authors.

Other files linked to this repository, with the exception of some of the assets, also hold
the same criteria.

---------------------------------------------------------------------------------------------------->

<!DOCTYPE html> 
<head>
  <title>CST BLocked</title>
  <link rel="icon" type="image/x-icon" href="./assets/favicon.ico">

  <style>
    input {
      width: 25%;
      margin-bottom: 3px;
      border-radius: 5px;
      height: 20px;
    }
    div,a {
      width: 20%;
      height: 20px;
      background-color: skyblue;
      border-radius: 5px;
      color: black;
      cursor: pointer;
      padding: 5px;
      border: none;
      text-decoration: none;
    }

    a:hover {
        text-decoration: underline;
    }

    * {
      font-family: "Lucida Console", "Menlo", "Monaco", "Courier", monospace;
    }
    body {
      background-color: rgb(218, 237, 255);
    }
    button {
        width: fit-content;
        height: 30px;
        background-color: burlywood;
        border-radius: 5px;
        color: white;
        cursor: pointer;
        padding: 5px;
        border: none;
        text-decoration: none;
    }
    #commands {
        width: 95% !important;
        height: fit-content !important;
        padding: 20px;
    }
    #output {
        width: 95% !important;
        height: 600px !important;
        overflow: scroll;
        padding: 20px;
        background:lightgreen !important;
    }
    .active {
        background-color: burlywood;
    }
    .not-active {
        background-color: grey;
    }
  </style>
</head>
<body>
<div>
    <a href="./index.html">Main page</a><br>
 </div>
<noscript><h2>Note: JavaScript is disabled in your browser. Please enable it for terminal functionality.</h2></noscript>
  
  <h1>Admin Panel</h1>

    <?php 

        $username = $_POST['username'];
        $password = $_POST['password'];
        if ($username=="TBD") {
            if ($password=="TBD") {
                echo("> Login successfull with: ".$username."@<span id='passwordLoggedInWith'>".str_repeat("*",strlen($password))."</span> ");
                echo("<a onclick=\"document.getElementById('passwordLoggedInWith').innerHTML='".$password."'; window.setTimeout(function(){ document.getElementById('passwordLoggedInWith').innerHTML='".str_repeat("*",strlen($password))."'},1000); \">Show password</a><br>");
            } else {
                echo("<br>");
                die("> Invalid username/password");
            }
        } else {
            echo("<br>");
            die("> Invalid username/password");
        }
    
    ?>

    > Initializing... <br>
    > Loading assets... <br>
    > Successfull initialized <br><br>
    
    <center>
    <div id="commands">
        <button class="active"     onclick="document.querySelector('.active').className='not-active';this.className='active'; setOutput(this.innerHTML);">Home</button> 
        <button class="not-active" onclick="document.querySelector('.active').className='not-active';this.className='active'; setOutput(this.innerHTML);">Get settings</button>
        <button class="not-active" onclick="document.querySelector('.active').className='not-active';this.className='active'; setOutput(this.innerHTML);">Change settings</button>
        <button class="not-active" onclick="document.querySelector('.active').className='not-active';this.className='active'; setOutput(this.innerHTML);">Change lockdown</button>
    </div>
    </center>
    <br>
    <center>
    <div id="output">
    </div>
    </center>


    <script>
        setOutput('Home');
        function setOutput(outDataType) {
            out = document.querySelector('#output');
            switch (outDataType) {
                case "Home":
                    out.innerHTML = "Home";
                    break;
                case "Get settings":
                    out.innerHTML = "Get settings";
                    break;
                case "Change settings":
                    out.innerHTML = "Change settings";
                    break;
                default: {
                    out.innerHTML = "An error occured";
                    
                }
            }
        }
    </script>



    
        
</body>
