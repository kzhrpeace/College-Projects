for $j in
doc("car.xml")/carList/car
where contains ($j/@make, "Tesla")
return 
   <Description>
   {string($j/@model)}
   </Description>

