
<?php
   $to_email = "simon@wirz.com, bmctilton@gmail.com";
   $subject = "CST Issue";
   $body = ("User " . $_GET['issueUser'] . ", has submited an issue at " . date('d-m-y h:i:s') . " with the following message:\n" . $_GET['issueBody']);
   $headers = "From: CST Command Line";
 
   if (mail($to_email, $subject, $body, $headers)) {
      echo("Successfully sent");
   } else {
      echo("Email sending failed");
   }
?>

<script>
   window.location = "./index.html";

</script>