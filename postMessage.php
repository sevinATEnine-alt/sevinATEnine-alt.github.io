<a href="./messages.php">Back to messages</a><br>

<?php
    function startsWith ($string, $startString)
    {
        $len = strlen($startString);
        return (substr($string, 0, $len) === $startString);
    }

  $servername = "localhost";
  $username = "elem435_cst_usr";
  $password = "#3rm|n@2";
  $dbname = "elem435_cst";

  // Create connection
  $conn = new mysqli($servername, $username, $password, $dbname);
  // Check connection
  if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
  }
    if (startsWith(($_GET['username']), "[")) {
        echo(('You are not ' . $_GET['username'] . '. Don\'t try to fake as them. Anything starting with `[` is reserved for root.'));
        die();
    };

    $sql = "INSERT INTO Messages (username, messageContent) VALUES ('" . $_GET['username'] . "', '" . $_GET['message'] . "')";

    if ($conn->query($sql) === TRUE) {
    echo "Successfully posted";
    } else {
    echo "Error: " . $sql . "<br>" . $conn->error;
    }
  
    $conn->close();


  ?>

<br>
