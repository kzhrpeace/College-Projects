let $last := count(form/bibl)
for $bibl at $position in doc("testcode.xml")//form/bibl 
return
<div>
{
for $biblScope in $bibl/biblScope/text()
    return
    $biblScope
}
{if ($position ne $last) then ',' else '@'}
</div>  