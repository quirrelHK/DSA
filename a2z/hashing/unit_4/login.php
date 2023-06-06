<?php
$existingUserID = 'admin';
$existingPassword = 'password';
$submittedUserID = $_POST['userid'];
$submittedPassword = $_POST['password'];
if ($submittedUserID === $existingUserID && $submittedPassword === $existingPassword) {
echo '<h2>Welcome ' . $existingUserID . '!</h2>';
} else {
echo '<h2>Login Failed. Please check your credentials.</h2>';
}
?>
