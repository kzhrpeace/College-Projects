declare function local:mileageDiscount($distance as xs:decimal?, $percentDiscount as xs:decimal?)

as xs:decimal? {
  let $mileageDiscount := $distance * $percentDiscount div 100
  return $mileageDiscount
};

for $distance in doc("car.xml")/carList/car/distance
let $percentage := 20
return ("The discount is ",(local:mileageDiscount($distance,$percentage))) 