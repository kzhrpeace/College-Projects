for $validPolicy in doc("insurancePolicy.xml")/policyList/insurancePolicy/renewal,
$test in doc("Customer.xml")/customerList/customer

 
where ($test/@id = $validPolicy/customerID) 
return ("Valid Policy List: " , $validPolicy, $test)




