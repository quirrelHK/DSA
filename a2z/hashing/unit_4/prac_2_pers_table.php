<?php
// Assuming you have a database connection
$dbHost = "localhost";
$dbUser = "sqluser";
$dbPass = "password";
$dbName = "information_schema";

// Create a database connection
$conn = mysqli($dbHost, $dbUser, $dbPass, $dbName);

// Check if the connection was successful
if (!$conn) {
    die("Database connection failed: " . mysqli_error());
}

// Assuming you receive the department numbers as a comma-separated list in the lstdno parameter
$lstdno = $_GET['lstdno'];

// Split the comma-separated list into an array
$deptNumbers = explode(",", $lstdno);

// Prepare the SQL query to select records from the PERS table
$query = "SELECT * FROM APPLICABLE_ROLES WHERE dno LIKE ?";
$stmt = mysqli_prepare($conn, $query);

// Bind the department number parameter to the query
mysqli_stmt_bind_param($stmt, "s", $deptNumber);

// Loop through each department number and execute the query
foreach ($deptNumbers as $deptNumber) {
    // Add a wildcard character to the department number to perform a similar search
    $deptNumber = "%" . $deptNumber . "%";
    
    // Execute the query
    mysqli_stmt_execute($stmt);
    
    // Get the result set
    $result = mysqli_stmt_get_result($stmt);
    
    // Display the records
    while ($row = mysqli_fetch_assoc($result)) {
        echo "ID: " . $row['id'] . "<br>";
        echo "Name: " . $row['name'] . "<br>";
        echo "Department Number: " . $row['dno'] . "<br><br>";
    }
}

// Close the statement and database connection
mysqli_stmt_close($stmt);
mysqli_close($conn);
?>
