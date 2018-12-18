<?php
$date = date("dMYHis");
$target_path = "uploadedfiles/"; //here folder name 
$target_path = $target_path . $date  . basename($_FILES['file']['name']);

error_log("Upload File >>" . $target_path . $_FILES['error'] . " \r\n", 3,
"Log.log");

error_log("Upload File >>" . basename($_FILES['file']['name']) . "     \r\n",
3, "Log.log");

 if(move_uploaded_file($_FILES['file']['tmp_name'], $target_path)) {
    echo "The file " . basename($_FILES['file']['name']) .
   " has been uploaded";
   } else {
  echo "There was an error uploading the file, please try again!!";
  }
 ?>
