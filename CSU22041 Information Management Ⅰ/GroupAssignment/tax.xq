declare function local:tax($price as xs:decimal?,$percentTax as xs:decimal?)
as xs:decimal? {
   let $tax := $price * $percentTax div 100
   return $tax
};

let $originalAmount := 2000
let $percentage:= 30
return(local:tax($originalAmount,$percentage))