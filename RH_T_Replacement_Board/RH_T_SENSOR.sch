<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="9.6.2">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="24" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="88" name="SimResults" color="9" fill="1" visible="yes" active="yes"/>
<layer number="89" name="SimProbes" color="9" fill="1" visible="yes" active="yes"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="yes" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="2023-06-30_23-55-05_Library">
<packages>
<package name="0402_AVX">
<smd name="1" x="-0.5334" y="0" dx="0.762" dy="0.6096" layer="1"/>
<smd name="2" x="0.5334" y="0" dx="0.762" dy="0.6096" layer="1"/>
<wire x1="0" y1="0.3048" x2="3.4798" y2="0.3048" width="0.1524" layer="47"/>
<wire x1="0" y1="-0.3048" x2="3.4798" y2="-0.3048" width="0.1524" layer="47"/>
<wire x1="3.0988" y1="0.3048" x2="3.0988" y2="1.5748" width="0.1524" layer="47"/>
<wire x1="3.0988" y1="-0.3048" x2="3.0988" y2="-1.5748" width="0.1524" layer="47"/>
<wire x1="3.0988" y1="0.3048" x2="2.9718" y2="0.5588" width="0.1524" layer="47"/>
<wire x1="3.0988" y1="0.3048" x2="3.2258" y2="0.5588" width="0.1524" layer="47"/>
<wire x1="2.9718" y1="0.5588" x2="3.2258" y2="0.5588" width="0.1524" layer="47"/>
<wire x1="3.0988" y1="-0.3048" x2="2.9718" y2="-0.5588" width="0.1524" layer="47"/>
<wire x1="3.0988" y1="-0.3048" x2="3.2258" y2="-0.5588" width="0.1524" layer="47"/>
<wire x1="2.9718" y1="-0.5588" x2="3.2258" y2="-0.5588" width="0.1524" layer="47"/>
<wire x1="-0.5588" y1="0" x2="-0.5588" y2="3.2258" width="0.1524" layer="47"/>
<wire x1="0.5588" y1="0" x2="0.5588" y2="3.2258" width="0.1524" layer="47"/>
<wire x1="-0.5588" y1="2.8448" x2="-1.8288" y2="2.8448" width="0.1524" layer="47"/>
<wire x1="0.5588" y1="2.8448" x2="1.8288" y2="2.8448" width="0.1524" layer="47"/>
<wire x1="-0.5588" y1="2.8448" x2="-0.8128" y2="2.9718" width="0.1524" layer="47"/>
<wire x1="-0.5588" y1="2.8448" x2="-0.8128" y2="2.7178" width="0.1524" layer="47"/>
<wire x1="-0.8128" y1="2.9718" x2="-0.8128" y2="2.7178" width="0.1524" layer="47"/>
<wire x1="0.5588" y1="2.8448" x2="0.8128" y2="2.9718" width="0.1524" layer="47"/>
<wire x1="0.5588" y1="2.8448" x2="0.8128" y2="2.7178" width="0.1524" layer="47"/>
<wire x1="0.8128" y1="2.9718" x2="0.8128" y2="2.7178" width="0.1524" layer="47"/>
<wire x1="0.1524" y1="0" x2="0.1524" y2="-3.2258" width="0.1524" layer="47"/>
<wire x1="0.5588" y1="0" x2="0.5588" y2="-3.2258" width="0.1524" layer="47"/>
<wire x1="0.1524" y1="-2.8448" x2="-1.1176" y2="-2.8448" width="0.1524" layer="47"/>
<wire x1="0.5588" y1="-2.8448" x2="1.8288" y2="-2.8448" width="0.1524" layer="47"/>
<wire x1="0.1524" y1="-2.8448" x2="-0.1016" y2="-2.7178" width="0.1524" layer="47"/>
<wire x1="0.1524" y1="-2.8448" x2="-0.1016" y2="-2.9718" width="0.1524" layer="47"/>
<wire x1="-0.1016" y1="-2.7178" x2="-0.1016" y2="-2.9718" width="0.1524" layer="47"/>
<wire x1="0.5588" y1="-2.8448" x2="0.8128" y2="-2.7178" width="0.1524" layer="47"/>
<wire x1="0.5588" y1="-2.8448" x2="0.8128" y2="-2.9718" width="0.1524" layer="47"/>
<wire x1="0.8128" y1="-2.7178" x2="0.8128" y2="-2.9718" width="0.1524" layer="47"/>
<text x="-15.2035" y="-7.1628" size="1.27" layer="47" ratio="6">Default Padstyle: RX30Y24D0T</text>
<text x="-18.0848" y="-9.7028" size="1.27" layer="47" ratio="6">Alternate 1 Padstyle: OX60Y90D30P</text>
<text x="-18.0848" y="-12.2428" size="1.27" layer="47" ratio="6">Alternate 2 Padstyle: OX90Y60D30P</text>
<text x="3.6068" y="-0.3175" size="0.635" layer="47" ratio="4">0.024in/0.61mm</text>
<text x="-4.0424" y="3.3528" size="0.635" layer="47" ratio="4">0.044in/1.118mm</text>
<text x="-3.6868" y="-3.9878" size="0.635" layer="47" ratio="4">0.016in/0.406mm</text>
<wire x1="-0.1524" y1="-0.3048" x2="-0.1524" y2="0.3048" width="0.1524" layer="51"/>
<wire x1="-0.1524" y1="0.3048" x2="-0.5588" y2="0.3048" width="0.1524" layer="51"/>
<wire x1="-0.5588" y1="0.3048" x2="-0.5588" y2="-0.3048" width="0.1524" layer="51"/>
<wire x1="-0.5588" y1="-0.3048" x2="-0.1524" y2="-0.3048" width="0.1524" layer="51"/>
<wire x1="0.1524" y1="0.3048" x2="0.1524" y2="-0.3048" width="0.1524" layer="51"/>
<wire x1="0.1524" y1="-0.3048" x2="0.5588" y2="-0.3048" width="0.1524" layer="51"/>
<wire x1="0.5588" y1="-0.3048" x2="0.5588" y2="0.3048" width="0.1524" layer="51"/>
<wire x1="0.5588" y1="0.3048" x2="0.1524" y2="0.3048" width="0.1524" layer="51"/>
<wire x1="-0.5588" y1="-0.3048" x2="0.5588" y2="-0.3048" width="0.1524" layer="51"/>
<wire x1="0.5588" y1="-0.3048" x2="0.5588" y2="0.3048" width="0.1524" layer="51"/>
<wire x1="0.5588" y1="0.3048" x2="-0.5588" y2="0.3048" width="0.1524" layer="51"/>
<wire x1="-0.5588" y1="0.3048" x2="-0.5588" y2="-0.3048" width="0.1524" layer="51"/>
<polygon width="0.0254" layer="41">
<vertex x="-0.1016" y="0.254"/>
<vertex x="0.1016" y="0.254"/>
<vertex x="0.1016" y="-0.254"/>
<vertex x="-0.1016" y="-0.254"/>
</polygon>
<polygon width="0.0254" layer="41">
<vertex x="-0.1016" y="0.3048"/>
<vertex x="0.1016" y="0.3048"/>
<vertex x="0.1016" y="-0.3048"/>
<vertex x="-0.1016" y="-0.3048"/>
</polygon>
<text x="-3.2712" y="-0.635" size="1.27" layer="27" ratio="6">&gt;Name</text>
<text x="-1.7288" y="-0.635" size="1.27" layer="27" ratio="6">&gt;Value</text>
</package>
<package name="0402_AVX-M">
<smd name="1" x="-0.635" y="0" dx="0.9652" dy="0.6604" layer="1"/>
<smd name="2" x="0.635" y="0" dx="0.9652" dy="0.6604" layer="1"/>
<wire x1="0" y1="0.3048" x2="3.4798" y2="0.3048" width="0.1524" layer="47"/>
<wire x1="0" y1="-0.3048" x2="3.4798" y2="-0.3048" width="0.1524" layer="47"/>
<wire x1="3.0988" y1="0.3048" x2="3.0988" y2="1.5748" width="0.1524" layer="47"/>
<wire x1="3.0988" y1="-0.3048" x2="3.0988" y2="-1.5748" width="0.1524" layer="47"/>
<wire x1="3.0988" y1="0.3048" x2="2.9718" y2="0.5588" width="0.1524" layer="47"/>
<wire x1="3.0988" y1="0.3048" x2="3.2258" y2="0.5588" width="0.1524" layer="47"/>
<wire x1="2.9718" y1="0.5588" x2="3.2258" y2="0.5588" width="0.1524" layer="47"/>
<wire x1="3.0988" y1="-0.3048" x2="2.9718" y2="-0.5588" width="0.1524" layer="47"/>
<wire x1="3.0988" y1="-0.3048" x2="3.2258" y2="-0.5588" width="0.1524" layer="47"/>
<wire x1="2.9718" y1="-0.5588" x2="3.2258" y2="-0.5588" width="0.1524" layer="47"/>
<wire x1="-0.5588" y1="0" x2="-0.5588" y2="3.2258" width="0.1524" layer="47"/>
<wire x1="0.5588" y1="0" x2="0.5588" y2="3.2258" width="0.1524" layer="47"/>
<wire x1="-0.5588" y1="2.8448" x2="-1.8288" y2="2.8448" width="0.1524" layer="47"/>
<wire x1="0.5588" y1="2.8448" x2="1.8288" y2="2.8448" width="0.1524" layer="47"/>
<wire x1="-0.5588" y1="2.8448" x2="-0.8128" y2="2.9718" width="0.1524" layer="47"/>
<wire x1="-0.5588" y1="2.8448" x2="-0.8128" y2="2.7178" width="0.1524" layer="47"/>
<wire x1="-0.8128" y1="2.9718" x2="-0.8128" y2="2.7178" width="0.1524" layer="47"/>
<wire x1="0.5588" y1="2.8448" x2="0.8128" y2="2.9718" width="0.1524" layer="47"/>
<wire x1="0.5588" y1="2.8448" x2="0.8128" y2="2.7178" width="0.1524" layer="47"/>
<wire x1="0.8128" y1="2.9718" x2="0.8128" y2="2.7178" width="0.1524" layer="47"/>
<wire x1="0.1524" y1="0" x2="0.1524" y2="-3.2258" width="0.1524" layer="47"/>
<wire x1="0.5588" y1="0" x2="0.5588" y2="-3.2258" width="0.1524" layer="47"/>
<wire x1="0.1524" y1="-2.8448" x2="-1.1176" y2="-2.8448" width="0.1524" layer="47"/>
<wire x1="0.5588" y1="-2.8448" x2="1.8288" y2="-2.8448" width="0.1524" layer="47"/>
<wire x1="0.1524" y1="-2.8448" x2="-0.1016" y2="-2.7178" width="0.1524" layer="47"/>
<wire x1="0.1524" y1="-2.8448" x2="-0.1016" y2="-2.9718" width="0.1524" layer="47"/>
<wire x1="-0.1016" y1="-2.7178" x2="-0.1016" y2="-2.9718" width="0.1524" layer="47"/>
<wire x1="0.5588" y1="-2.8448" x2="0.8128" y2="-2.7178" width="0.1524" layer="47"/>
<wire x1="0.5588" y1="-2.8448" x2="0.8128" y2="-2.9718" width="0.1524" layer="47"/>
<wire x1="0.8128" y1="-2.7178" x2="0.8128" y2="-2.9718" width="0.1524" layer="47"/>
<text x="-15.2035" y="-7.1882" size="1.27" layer="47" ratio="6">Default Padstyle: RX38Y26D0T</text>
<text x="-18.0848" y="-9.7282" size="1.27" layer="47" ratio="6">Alternate 1 Padstyle: OX60Y90D30P</text>
<text x="-18.0848" y="-12.2682" size="1.27" layer="47" ratio="6">Alternate 2 Padstyle: OX90Y60D30P</text>
<text x="3.6068" y="-0.3175" size="0.635" layer="47" ratio="4">0.024in/0.61mm</text>
<text x="-4.0424" y="3.3528" size="0.635" layer="47" ratio="4">0.044in/1.118mm</text>
<text x="-3.6868" y="-3.9878" size="0.635" layer="47" ratio="4">0.016in/0.406mm</text>
<wire x1="-1.8796" y1="0" x2="-2.032" y2="0" width="0.1524" layer="21" curve="-180"/>
<wire x1="-2.032" y1="0" x2="-1.8796" y2="0" width="0.1524" layer="21" curve="-180"/>
<wire x1="-0.1524" y1="-0.3048" x2="-0.1524" y2="0.3048" width="0.1524" layer="51"/>
<wire x1="-0.1524" y1="0.3048" x2="-0.5588" y2="0.3048" width="0.1524" layer="51"/>
<wire x1="-0.5588" y1="0.3048" x2="-0.5588" y2="-0.3048" width="0.1524" layer="51"/>
<wire x1="-0.5588" y1="-0.3048" x2="-0.1524" y2="-0.3048" width="0.1524" layer="51"/>
<wire x1="0.1524" y1="0.3048" x2="0.1524" y2="-0.3048" width="0.1524" layer="51"/>
<wire x1="0.1524" y1="-0.3048" x2="0.5588" y2="-0.3048" width="0.1524" layer="51"/>
<wire x1="0.5588" y1="-0.3048" x2="0.5588" y2="0.3048" width="0.1524" layer="51"/>
<wire x1="0.5588" y1="0.3048" x2="0.1524" y2="0.3048" width="0.1524" layer="51"/>
<wire x1="-0.5588" y1="-0.3048" x2="0.5588" y2="-0.3048" width="0.1524" layer="51"/>
<wire x1="0.5588" y1="-0.3048" x2="0.5588" y2="0.3048" width="0.1524" layer="51"/>
<wire x1="0.5588" y1="0.3048" x2="-0.5588" y2="0.3048" width="0.1524" layer="51"/>
<wire x1="-0.5588" y1="0.3048" x2="-0.5588" y2="-0.3048" width="0.1524" layer="51"/>
<wire x1="-0.4318" y1="0" x2="-0.5842" y2="0" width="0" layer="51" curve="-180"/>
<wire x1="-0.5842" y1="0" x2="-0.4318" y2="0" width="0" layer="51" curve="-180"/>
<polygon width="0.1524" layer="41">
<vertex x="-0.1016" y="0.254"/>
<vertex x="0.1016" y="0.254"/>
<vertex x="0.1016" y="-0.254"/>
<vertex x="-0.1016" y="-0.254"/>
</polygon>
<polygon width="0.1524" layer="41">
<vertex x="-0.1016" y="0.3048"/>
<vertex x="0.1016" y="0.3048"/>
<vertex x="0.1016" y="-0.3048"/>
<vertex x="-0.1016" y="-0.3048"/>
</polygon>
<text x="-3.2712" y="-0.635" size="1.27" layer="27" ratio="6">&gt;Name</text>
<text x="-1.7288" y="-0.635" size="1.27" layer="27" ratio="6">&gt;Value</text>
</package>
<package name="0402_AVX-L">
<smd name="1" x="-0.4318" y="0" dx="0.5588" dy="0.5588" layer="1"/>
<smd name="2" x="0.4318" y="0" dx="0.5588" dy="0.5588" layer="1"/>
<wire x1="0" y1="0.3048" x2="3.4798" y2="0.3048" width="0.1524" layer="47"/>
<wire x1="0" y1="-0.3048" x2="3.4798" y2="-0.3048" width="0.1524" layer="47"/>
<wire x1="3.0988" y1="0.3048" x2="3.0988" y2="1.5748" width="0.1524" layer="47"/>
<wire x1="3.0988" y1="-0.3048" x2="3.0988" y2="-1.5748" width="0.1524" layer="47"/>
<wire x1="3.0988" y1="0.3048" x2="2.9718" y2="0.5588" width="0.1524" layer="47"/>
<wire x1="3.0988" y1="0.3048" x2="3.2258" y2="0.5588" width="0.1524" layer="47"/>
<wire x1="2.9718" y1="0.5588" x2="3.2258" y2="0.5588" width="0.1524" layer="47"/>
<wire x1="3.0988" y1="-0.3048" x2="2.9718" y2="-0.5588" width="0.1524" layer="47"/>
<wire x1="3.0988" y1="-0.3048" x2="3.2258" y2="-0.5588" width="0.1524" layer="47"/>
<wire x1="2.9718" y1="-0.5588" x2="3.2258" y2="-0.5588" width="0.1524" layer="47"/>
<wire x1="-0.5588" y1="0" x2="-0.5588" y2="3.2258" width="0.1524" layer="47"/>
<wire x1="0.5588" y1="0" x2="0.5588" y2="3.2258" width="0.1524" layer="47"/>
<wire x1="-0.5588" y1="2.8448" x2="-1.8288" y2="2.8448" width="0.1524" layer="47"/>
<wire x1="0.5588" y1="2.8448" x2="1.8288" y2="2.8448" width="0.1524" layer="47"/>
<wire x1="-0.5588" y1="2.8448" x2="-0.8128" y2="2.9718" width="0.1524" layer="47"/>
<wire x1="-0.5588" y1="2.8448" x2="-0.8128" y2="2.7178" width="0.1524" layer="47"/>
<wire x1="-0.8128" y1="2.9718" x2="-0.8128" y2="2.7178" width="0.1524" layer="47"/>
<wire x1="0.5588" y1="2.8448" x2="0.8128" y2="2.9718" width="0.1524" layer="47"/>
<wire x1="0.5588" y1="2.8448" x2="0.8128" y2="2.7178" width="0.1524" layer="47"/>
<wire x1="0.8128" y1="2.9718" x2="0.8128" y2="2.7178" width="0.1524" layer="47"/>
<wire x1="0.1524" y1="0" x2="0.1524" y2="-3.2258" width="0.1524" layer="47"/>
<wire x1="0.5588" y1="0" x2="0.5588" y2="-3.2258" width="0.1524" layer="47"/>
<wire x1="0.1524" y1="-2.8448" x2="-1.1176" y2="-2.8448" width="0.1524" layer="47"/>
<wire x1="0.5588" y1="-2.8448" x2="1.8288" y2="-2.8448" width="0.1524" layer="47"/>
<wire x1="0.1524" y1="-2.8448" x2="-0.1016" y2="-2.7178" width="0.1524" layer="47"/>
<wire x1="0.1524" y1="-2.8448" x2="-0.1016" y2="-2.9718" width="0.1524" layer="47"/>
<wire x1="-0.1016" y1="-2.7178" x2="-0.1016" y2="-2.9718" width="0.1524" layer="47"/>
<wire x1="0.5588" y1="-2.8448" x2="0.8128" y2="-2.7178" width="0.1524" layer="47"/>
<wire x1="0.5588" y1="-2.8448" x2="0.8128" y2="-2.9718" width="0.1524" layer="47"/>
<wire x1="0.8128" y1="-2.7178" x2="0.8128" y2="-2.9718" width="0.1524" layer="47"/>
<text x="-15.2035" y="-7.1374" size="1.27" layer="47" ratio="6">Default Padstyle: RX22Y22D0T</text>
<text x="-18.0848" y="-9.6774" size="1.27" layer="47" ratio="6">Alternate 1 Padstyle: OX60Y90D30P</text>
<text x="-18.0848" y="-12.2174" size="1.27" layer="47" ratio="6">Alternate 2 Padstyle: OX90Y60D30P</text>
<text x="3.6068" y="-0.3175" size="0.635" layer="47" ratio="4">0.024in/0.61mm</text>
<text x="-4.0424" y="3.3528" size="0.635" layer="47" ratio="4">0.044in/1.118mm</text>
<text x="-3.6868" y="-3.9878" size="0.635" layer="47" ratio="4">0.016in/0.406mm</text>
<wire x1="-1.4732" y1="0" x2="-1.6256" y2="0" width="0.1524" layer="21" curve="-180"/>
<wire x1="-1.6256" y1="0" x2="-1.4732" y2="0" width="0.1524" layer="21" curve="-180"/>
<wire x1="-0.1524" y1="-0.3048" x2="-0.1524" y2="0.3048" width="0.1524" layer="51"/>
<wire x1="-0.1524" y1="0.3048" x2="-0.5588" y2="0.3048" width="0.1524" layer="51"/>
<wire x1="-0.5588" y1="0.3048" x2="-0.5588" y2="-0.3048" width="0.1524" layer="51"/>
<wire x1="-0.5588" y1="-0.3048" x2="-0.1524" y2="-0.3048" width="0.1524" layer="51"/>
<wire x1="0.1524" y1="0.3048" x2="0.1524" y2="-0.3048" width="0.1524" layer="51"/>
<wire x1="0.1524" y1="-0.3048" x2="0.5588" y2="-0.3048" width="0.1524" layer="51"/>
<wire x1="0.5588" y1="-0.3048" x2="0.5588" y2="0.3048" width="0.1524" layer="51"/>
<wire x1="0.5588" y1="0.3048" x2="0.1524" y2="0.3048" width="0.1524" layer="51"/>
<wire x1="-0.5588" y1="-0.3048" x2="0.5588" y2="-0.3048" width="0.1524" layer="51"/>
<wire x1="0.5588" y1="-0.3048" x2="0.5588" y2="0.3048" width="0.1524" layer="51"/>
<wire x1="0.5588" y1="0.3048" x2="-0.5588" y2="0.3048" width="0.1524" layer="51"/>
<wire x1="-0.5588" y1="0.3048" x2="-0.5588" y2="-0.3048" width="0.1524" layer="51"/>
<wire x1="-0.2286" y1="0" x2="-0.381" y2="0" width="0" layer="51" curve="-180"/>
<wire x1="-0.381" y1="0" x2="-0.2286" y2="0" width="0" layer="51" curve="-180"/>
<polygon width="0.1524" layer="41">
<vertex x="-0.1016" y="0.254"/>
<vertex x="0.1016" y="0.254"/>
<vertex x="0.1016" y="-0.254"/>
<vertex x="-0.1016" y="-0.254"/>
</polygon>
<polygon width="0.1524" layer="41">
<vertex x="-0.1016" y="0.3048"/>
<vertex x="0.1016" y="0.3048"/>
<vertex x="0.1016" y="-0.3048"/>
<vertex x="-0.1016" y="-0.3048"/>
</polygon>
<text x="-3.2712" y="-0.635" size="1.27" layer="27" ratio="6">&gt;Name</text>
<text x="-1.7288" y="-0.635" size="1.27" layer="27" ratio="6">&gt;Value</text>
</package>
</packages>
<symbols>
<symbol name="CAPH">
<pin name="2" x="7.62" y="0" visible="off" length="short" direction="pas" swaplevel="1" rot="R180"/>
<pin name="1" x="0" y="0" visible="off" length="short" direction="pas" swaplevel="1"/>
<wire x1="3.4798" y1="-1.905" x2="3.4798" y2="1.905" width="0.2032" layer="94"/>
<wire x1="4.1148" y1="-1.905" x2="4.1148" y2="1.905" width="0.2032" layer="94"/>
<wire x1="4.1148" y1="0" x2="5.08" y2="0" width="0.2032" layer="94"/>
<wire x1="2.54" y1="0" x2="3.4798" y2="0" width="0.2032" layer="94"/>
<text x="-5.1531" y="-5.5499" size="3.48" layer="96" ratio="10">&gt;Value</text>
<text x="-4.0848" y="2.0701" size="3.48" layer="95" ratio="10">&gt;Name</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="0402YC104KAT2A" prefix="C">
<gates>
<gate name="A" symbol="CAPH" x="0" y="0" swaplevel="1"/>
</gates>
<devices>
<device name="0402_AVX" package="0402_AVX">
<connects>
<connect gate="A" pin="1" pad="1"/>
<connect gate="A" pin="2" pad="2"/>
</connects>
<technologies>
<technology name="">
<attribute name="COPYRIGHT" value="Copyright (C) 2023 Ultra Librarian. All rights reserved." constant="no"/>
<attribute name="MANUFACTURER_PART_NUMBER" value="0402YC104KAT2A" constant="no"/>
<attribute name="MFR_NAME" value="KYOCERA AVX" constant="no"/>
</technology>
</technologies>
</device>
<device name="0402_AVX-M" package="0402_AVX-M">
<connects>
<connect gate="A" pin="1" pad="1"/>
<connect gate="A" pin="2" pad="2"/>
</connects>
<technologies>
<technology name="">
<attribute name="COPYRIGHT" value="Copyright (C) 2023 Ultra Librarian. All rights reserved." constant="no"/>
<attribute name="MANUFACTURER_PART_NUMBER" value="0402YC104KAT2A" constant="no"/>
<attribute name="MFR_NAME" value="KYOCERA AVX" constant="no"/>
</technology>
</technologies>
</device>
<device name="0402_AVX-L" package="0402_AVX-L">
<connects>
<connect gate="A" pin="1" pad="1"/>
<connect gate="A" pin="2" pad="2"/>
</connects>
<technologies>
<technology name="">
<attribute name="COPYRIGHT" value="Copyright (C) 2023 Ultra Librarian. All rights reserved." constant="no"/>
<attribute name="MANUFACTURER_PART_NUMBER" value="0402YC104KAT2A" constant="no"/>
<attribute name="MFR_NAME" value="KYOCERA AVX" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="CAY16-332J4LF">
<packages>
<package name="RESCAF80P320X160X60-8N">
<wire x1="-0.9" y1="1.7" x2="0.9" y2="1.7" width="0.127" layer="51"/>
<wire x1="0.9" y1="1.7" x2="0.9" y2="-1.7" width="0.127" layer="51"/>
<wire x1="0.9" y1="-1.7" x2="-0.9" y2="-1.7" width="0.127" layer="51"/>
<wire x1="-0.9" y1="-1.7" x2="-0.9" y2="1.7" width="0.127" layer="51"/>
<wire x1="-0.9" y1="1.7" x2="0.9" y2="1.7" width="0.127" layer="21"/>
<wire x1="0.9" y1="-1.7" x2="-0.9" y2="-1.7" width="0.127" layer="21"/>
<wire x1="-1.61" y1="1.95" x2="1.61" y2="1.95" width="0.05" layer="39"/>
<wire x1="1.61" y1="1.95" x2="1.61" y2="-1.95" width="0.05" layer="39"/>
<wire x1="1.61" y1="-1.95" x2="-1.61" y2="-1.95" width="0.05" layer="39"/>
<wire x1="-1.61" y1="-1.95" x2="-1.61" y2="1.95" width="0.05" layer="39"/>
<circle x="-1.9" y="1.5" radius="0.1" width="0.2" layer="21"/>
<circle x="-1.9" y="1.5" radius="0.1" width="0.2" layer="51"/>
<text x="-1.6" y="2.1" size="1.27" layer="25">&gt;NAME</text>
<text x="-1.6" y="-3.3" size="1.27" layer="27">&gt;VALUE</text>
<smd name="1" x="-0.875" y="1.2" dx="0.97" dy="0.53" layer="1" roundness="25"/>
<smd name="2" x="-0.875" y="0.4" dx="0.97" dy="0.53" layer="1" roundness="25"/>
<smd name="3" x="-0.875" y="-0.4" dx="0.97" dy="0.53" layer="1" roundness="25"/>
<smd name="4" x="-0.875" y="-1.2" dx="0.97" dy="0.53" layer="1" roundness="25"/>
<smd name="5" x="0.875" y="-1.2" dx="0.97" dy="0.53" layer="1" roundness="25" rot="R180"/>
<smd name="6" x="0.875" y="-0.4" dx="0.97" dy="0.53" layer="1" roundness="25" rot="R180"/>
<smd name="7" x="0.875" y="0.4" dx="0.97" dy="0.53" layer="1" roundness="25" rot="R180"/>
<smd name="8" x="0.875" y="1.2" dx="0.97" dy="0.53" layer="1" roundness="25" rot="R180"/>
</package>
</packages>
<symbols>
<symbol name="CAY16-332J4LF">
<wire x1="-5.08" y1="2.54" x2="-4.445" y2="4.445" width="0.254" layer="94"/>
<wire x1="-4.445" y1="4.445" x2="-3.175" y2="0.635" width="0.254" layer="94"/>
<wire x1="-3.175" y1="0.635" x2="-1.905" y2="4.445" width="0.254" layer="94"/>
<wire x1="-1.905" y1="4.445" x2="-0.635" y2="0.635" width="0.254" layer="94"/>
<wire x1="-0.635" y1="0.635" x2="0.635" y2="4.445" width="0.254" layer="94"/>
<wire x1="0.635" y1="4.445" x2="1.905" y2="0.635" width="0.254" layer="94"/>
<wire x1="1.905" y1="0.635" x2="3.175" y2="4.445" width="0.254" layer="94"/>
<wire x1="3.175" y1="4.445" x2="4.445" y2="0.635" width="0.254" layer="94"/>
<wire x1="4.445" y1="0.635" x2="5.08" y2="2.54" width="0.254" layer="94"/>
<text x="-6.862440625" y="13.4635" size="2.54148125" layer="95">&gt;NAME</text>
<text x="-6.61396875" y="-15.7546" size="2.54331875" layer="96">&gt;VALUE</text>
<wire x1="-5.08" y1="7.62" x2="-4.445" y2="9.525" width="0.254" layer="94"/>
<wire x1="-4.445" y1="9.525" x2="-3.175" y2="5.715" width="0.254" layer="94"/>
<wire x1="-3.175" y1="5.715" x2="-1.905" y2="9.525" width="0.254" layer="94"/>
<wire x1="-1.905" y1="9.525" x2="-0.635" y2="5.715" width="0.254" layer="94"/>
<wire x1="-0.635" y1="5.715" x2="0.635" y2="9.525" width="0.254" layer="94"/>
<wire x1="0.635" y1="9.525" x2="1.905" y2="5.715" width="0.254" layer="94"/>
<wire x1="1.905" y1="5.715" x2="3.175" y2="9.525" width="0.254" layer="94"/>
<wire x1="3.175" y1="9.525" x2="4.445" y2="5.715" width="0.254" layer="94"/>
<wire x1="4.445" y1="5.715" x2="5.08" y2="7.62" width="0.254" layer="94"/>
<wire x1="-5.08" y1="-2.54" x2="-4.445" y2="-0.635" width="0.254" layer="94"/>
<wire x1="-4.445" y1="-0.635" x2="-3.175" y2="-4.445" width="0.254" layer="94"/>
<wire x1="-3.175" y1="-4.445" x2="-1.905" y2="-0.635" width="0.254" layer="94"/>
<wire x1="-1.905" y1="-0.635" x2="-0.635" y2="-4.445" width="0.254" layer="94"/>
<wire x1="-0.635" y1="-4.445" x2="0.635" y2="-0.635" width="0.254" layer="94"/>
<wire x1="0.635" y1="-0.635" x2="1.905" y2="-4.445" width="0.254" layer="94"/>
<wire x1="1.905" y1="-4.445" x2="3.175" y2="-0.635" width="0.254" layer="94"/>
<wire x1="3.175" y1="-0.635" x2="4.445" y2="-4.445" width="0.254" layer="94"/>
<wire x1="4.445" y1="-4.445" x2="5.08" y2="-2.54" width="0.254" layer="94"/>
<wire x1="-5.08" y1="-7.62" x2="-4.445" y2="-5.715" width="0.254" layer="94"/>
<wire x1="-4.445" y1="-5.715" x2="-3.175" y2="-9.525" width="0.254" layer="94"/>
<wire x1="-3.175" y1="-9.525" x2="-1.905" y2="-5.715" width="0.254" layer="94"/>
<wire x1="-1.905" y1="-5.715" x2="-0.635" y2="-9.525" width="0.254" layer="94"/>
<wire x1="-0.635" y1="-9.525" x2="0.635" y2="-5.715" width="0.254" layer="94"/>
<wire x1="0.635" y1="-5.715" x2="1.905" y2="-9.525" width="0.254" layer="94"/>
<wire x1="1.905" y1="-9.525" x2="3.175" y2="-5.715" width="0.254" layer="94"/>
<wire x1="3.175" y1="-5.715" x2="4.445" y2="-9.525" width="0.254" layer="94"/>
<wire x1="4.445" y1="-9.525" x2="5.08" y2="-7.62" width="0.254" layer="94"/>
<wire x1="-7.62" y1="12.7" x2="7.62" y2="12.7" width="0.1524" layer="94"/>
<wire x1="7.62" y1="12.7" x2="7.62" y2="-12.7" width="0.1524" layer="94"/>
<wire x1="7.62" y1="-12.7" x2="-7.62" y2="-12.7" width="0.1524" layer="94"/>
<wire x1="-7.62" y1="-12.7" x2="-7.62" y2="12.7" width="0.1524" layer="94"/>
<pin name="1" x="-10.16" y="7.62" visible="pad" length="middle" direction="pas"/>
<pin name="2" x="-10.16" y="2.54" visible="pad" length="middle" direction="pas"/>
<pin name="3" x="-10.16" y="-2.54" visible="pad" length="middle" direction="pas"/>
<pin name="4" x="-10.16" y="-7.62" visible="pad" length="middle" direction="pas"/>
<pin name="5" x="10.16" y="-7.62" visible="pad" length="middle" direction="pas" rot="R180"/>
<pin name="6" x="10.16" y="-2.54" visible="pad" length="middle" direction="pas" rot="R180"/>
<pin name="7" x="10.16" y="2.54" visible="pad" length="middle" direction="pas" rot="R180"/>
<pin name="8" x="10.16" y="7.62" visible="pad" length="middle" direction="pas" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="CAY16-332J4LF" prefix="RN">
<description>Res Thick Film Array 75 Ohm 5% 0.25W(1/4W) ?200ppm/C ISOL Molded 8-Pin 1206(4 X 0603) Convex SMD T/R  </description>
<gates>
<gate name="G$1" symbol="CAY16-332J4LF" x="0" y="0"/>
</gates>
<devices>
<device name="" package="RESCAF80P320X160X60-8N">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
<connect gate="G$1" pin="4" pad="4"/>
<connect gate="G$1" pin="5" pad="5"/>
<connect gate="G$1" pin="6" pad="6"/>
<connect gate="G$1" pin="7" pad="7"/>
<connect gate="G$1" pin="8" pad="8"/>
</connects>
<technologies>
<technology name="">
<attribute name="MANUFACTURER" value="Bourns"/>
<attribute name="STANDARD" value="IPC-7351B"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="untitled">
<packages>
<package name="DEB0006A">
<smd name="1" x="-1.4" y="1" dx="0.6" dy="0.4" layer="1"/>
<smd name="2" x="-1.4" y="0" dx="0.6" dy="0.4" layer="1"/>
<smd name="3" x="-1.4" y="-1" dx="0.6" dy="0.4" layer="1"/>
<smd name="4" x="1.4" y="-1" dx="0.6" dy="0.4" layer="1"/>
<smd name="5" x="1.4" y="0" dx="0.6" dy="0.4" layer="1"/>
<smd name="6" x="1.4" y="1" dx="0.6" dy="0.4" layer="1"/>
<smd name="7" x="0" y="0" dx="1.5" dy="2.4" layer="1" cream="no"/>
<pad name="8" x="0" y="-0.9398" drill="0.2032" diameter="0.508"/>
<pad name="9" x="0" y="0.9398" drill="0.2032" diameter="0.508"/>
<pad name="10" x="0.508" y="0" drill="0.2032" diameter="0.508"/>
<pad name="11" x="-0.508" y="0" drill="0.2032" diameter="0.508"/>
<wire x1="-1.4986" y1="-1.4986" x2="-1.4986" y2="1.4986" width="0.1524" layer="51"/>
<wire x1="-1.4986" y1="1.4986" x2="1.4986" y2="1.4986" width="0.1524" layer="51"/>
<wire x1="-1.4986" y1="-1.4986" x2="1.4986" y2="-1.4986" width="0.1524" layer="51"/>
<wire x1="1.4986" y1="-1.4986" x2="1.4986" y2="1.4986" width="0.1524" layer="51"/>
<wire x1="-0.7112" y1="0.889" x2="-1.0922" y2="0.889" width="0.1016" layer="51" curve="-180"/>
<wire x1="-1.0922" y1="0.889" x2="-0.7112" y2="0.889" width="0.1016" layer="51" curve="-180"/>
<polygon width="0.0254" layer="31">
<vertex x="-0.69" y="-1.109996875"/>
<vertex x="-0.69" y="-0.15"/>
<vertex x="-0.64" y="-0.1"/>
<vertex x="0.64" y="-0.1"/>
<vertex x="0.69" y="-0.15"/>
<vertex x="0.69" y="-1.109996875"/>
<vertex x="0.64" y="-1.159996875"/>
<vertex x="-0.64" y="-1.159996875"/>
</polygon>
<polygon width="0.0254" layer="31">
<vertex x="0.69" y="1.109996875"/>
<vertex x="0.69" y="0.15"/>
<vertex x="0.64" y="0.1"/>
<vertex x="-0.64" y="0.1"/>
<vertex x="-0.69" y="0.15"/>
<vertex x="-0.69" y="1.109996875"/>
<vertex x="-0.64" y="1.159996875"/>
<vertex x="0.64" y="1.159996875"/>
</polygon>
<text x="-1.4986" y="2.1844" size="1.27" layer="21" ratio="6" rot="SR0">Designator56</text>
<text x="-1.7272" y="-0.635" size="1.27" layer="27" ratio="6" rot="SR0">&gt;Value</text>
<text x="-3.2766" y="-0.635" size="1.27" layer="27" ratio="6" rot="SR0">&gt;Name</text>
</package>
<package name="DEB0006A_NV">
<smd name="1" x="-1.4" y="1" dx="0.6" dy="0.4" layer="1"/>
<smd name="2" x="-1.4" y="0" dx="0.6" dy="0.4" layer="1"/>
<smd name="3" x="-1.4" y="-1" dx="0.6" dy="0.4" layer="1"/>
<smd name="4" x="1.4" y="-1" dx="0.6" dy="0.4" layer="1"/>
<smd name="5" x="1.4" y="0" dx="0.6" dy="0.4" layer="1"/>
<smd name="6" x="1.4" y="1" dx="0.6" dy="0.4" layer="1"/>
<smd name="7" x="0" y="0" dx="1.5" dy="2.4" layer="1" cream="no"/>
<wire x1="-1.4986" y1="-1.4986" x2="-1.4986" y2="1.4986" width="0.1524" layer="51"/>
<wire x1="-1.4986" y1="1.4986" x2="1.4986" y2="1.4986" width="0.1524" layer="51"/>
<wire x1="-1.4986" y1="-1.4986" x2="1.4986" y2="-1.4986" width="0.1524" layer="51"/>
<wire x1="1.4986" y1="-1.4986" x2="1.4986" y2="1.4986" width="0.1524" layer="51"/>
<wire x1="-0.7112" y1="0.889" x2="-1.0922" y2="0.889" width="0.1016" layer="51" curve="-180"/>
<wire x1="-1.0922" y1="0.889" x2="-0.7112" y2="0.889" width="0.1016" layer="51" curve="-180"/>
<polygon width="0.0254" layer="31">
<vertex x="-0.69" y="-1.109996875"/>
<vertex x="-0.69" y="-0.15"/>
<vertex x="-0.64" y="-0.1"/>
<vertex x="0.64" y="-0.1"/>
<vertex x="0.69" y="-0.15"/>
<vertex x="0.69" y="-1.109996875"/>
<vertex x="0.64" y="-1.159996875"/>
<vertex x="-0.64" y="-1.159996875"/>
</polygon>
<polygon width="0.0254" layer="31">
<vertex x="0.69" y="1.109996875"/>
<vertex x="0.69" y="0.15"/>
<vertex x="0.64" y="0.1"/>
<vertex x="-0.64" y="0.1"/>
<vertex x="-0.69" y="0.15"/>
<vertex x="-0.69" y="1.109996875"/>
<vertex x="-0.64" y="1.159996875"/>
<vertex x="0.64" y="1.159996875"/>
</polygon>
<text x="-1.7272" y="-0.635" size="1.27" layer="27" ratio="6" rot="SR0">&gt;Value</text>
<text x="-3.2766" y="-0.635" size="1.27" layer="27" ratio="6" rot="SR0">&gt;Name</text>
</package>
</packages>
<symbols>
<symbol name="HDC2021DEB">
<pin name="SDA" x="17.78" y="5.08" length="middle" rot="R180"/>
<pin name="GND" x="17.78" y="-10.16" length="middle" direction="pwr" rot="R180"/>
<pin name="ADDR" x="-17.78" y="-2.54" length="middle" direction="pwr"/>
<pin name="DRDY_INT" x="17.78" y="0" length="middle" direction="pwr" rot="R180"/>
<pin name="VDD" x="-17.78" y="7.62" length="middle" direction="pwr"/>
<pin name="SCL" x="17.78" y="7.62" length="middle" direction="oc" rot="R180"/>
<pin name="PAD" x="17.78" y="-5.08" length="middle" direction="pwr" rot="R180"/>
<wire x1="-12.7" y1="-12.7" x2="12.7" y2="-12.7" width="0.2032" layer="94"/>
<wire x1="12.7" y1="-12.7" x2="12.7" y2="12.7" width="0.2032" layer="94"/>
<wire x1="12.7" y1="12.7" x2="-12.7" y2="12.7" width="0.2032" layer="94"/>
<wire x1="-12.7" y1="12.7" x2="-12.7" y2="-12.7" width="0.2032" layer="94"/>
<text x="-4.7244" y="1.4986" size="2.0828" layer="95" ratio="6" rot="SR0">&gt;Name</text>
<text x="-5.3594" y="-1.0414" size="2.0828" layer="96" ratio="6" rot="SR0">&gt;Value</text>
<text x="-5.3594" y="-1.0414" size="2.0828" layer="96" ratio="6" rot="SR0">&gt;Value</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="PHDC2021DEBT" prefix="U">
<gates>
<gate name="A" symbol="HDC2021DEB" x="0" y="0"/>
</gates>
<devices>
<device name="" package="DEB0006A">
<connects>
<connect gate="A" pin="ADDR" pad="3"/>
<connect gate="A" pin="DRDY_INT" pad="4"/>
<connect gate="A" pin="GND" pad="2"/>
<connect gate="A" pin="PAD" pad="7"/>
<connect gate="A" pin="SCL" pad="6"/>
<connect gate="A" pin="SDA" pad="1"/>
<connect gate="A" pin="VDD" pad="5"/>
</connects>
<technologies>
<technology name="">
<attribute name="COPYRIGHT" value="Copyright (C) 2023 Ultra Librarian. All rights reserved." constant="no"/>
<attribute name="MANUFACTURER_PART_NUMBER" value="PHDC2021DEBT" constant="no"/>
<attribute name="MFR_NAME" value="Texas Instruments" constant="no"/>
<attribute name="REFDES" value="RefDes" constant="no"/>
<attribute name="TYPE" value="TYPE" constant="no"/>
</technology>
</technologies>
</device>
<device name="DEB0006A_NV" package="DEB0006A_NV">
<connects>
<connect gate="A" pin="ADDR" pad="3"/>
<connect gate="A" pin="DRDY_INT" pad="4"/>
<connect gate="A" pin="GND" pad="2"/>
<connect gate="A" pin="PAD" pad="7"/>
<connect gate="A" pin="SCL" pad="6"/>
<connect gate="A" pin="SDA" pad="1"/>
<connect gate="A" pin="VDD" pad="5"/>
</connects>
<technologies>
<technology name="">
<attribute name="COPYRIGHT" value="Copyright (C) 2023 Ultra Librarian. All rights reserved." constant="no"/>
<attribute name="MANUFACTURER_PART_NUMBER" value="PHDC2021DEBT" constant="no"/>
<attribute name="MFR_NAME" value="Texas Instruments" constant="no"/>
<attribute name="REFDES" value="RefDes" constant="no"/>
<attribute name="TYPE" value="TYPE" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="pinhead">
<description>&lt;b&gt;Simple Pin Header Connectors&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="1X06">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt; - 0.1"</description>
<wire x1="-7.62" y1="1.27" x2="-7.62" y2="-1.27" width="0.254" layer="21"/>
<wire x1="7.62" y1="1.27" x2="7.62" y2="-1.27" width="0.254" layer="21"/>
<wire x1="7.62" y1="1.27" x2="-5.08" y2="1.27" width="0.254" layer="21"/>
<wire x1="-5.08" y1="1.27" x2="-7.62" y2="1.27" width="0.254" layer="21"/>
<wire x1="7.62" y1="-1.27" x2="-7.62" y2="-1.27" width="0.254" layer="21"/>
<wire x1="-5.08" y1="1.27" x2="-5.08" y2="-1.27" width="0.254" layer="21"/>
<pad name="1" x="-6.35" y="0" drill="1.016" shape="square" rot="R90"/>
<pad name="2" x="-3.81" y="0" drill="1.016" shape="octagon" rot="R90"/>
<pad name="3" x="-1.27" y="0" drill="1.016" shape="octagon" rot="R90"/>
<pad name="4" x="1.27" y="0" drill="1.016" shape="octagon" rot="R90"/>
<pad name="5" x="3.81" y="0" drill="1.016" shape="octagon" rot="R90"/>
<pad name="6" x="6.35" y="0" drill="1.016" shape="octagon" rot="R90"/>
<text x="-7.6962" y="1.8288" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-7.62" y="-3.175" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="3.556" y1="-0.254" x2="4.064" y2="0.254" layer="51"/>
<rectangle x1="1.016" y1="-0.254" x2="1.524" y2="0.254" layer="51"/>
<rectangle x1="-1.524" y1="-0.254" x2="-1.016" y2="0.254" layer="51"/>
<rectangle x1="-4.064" y1="-0.254" x2="-3.556" y2="0.254" layer="51"/>
<rectangle x1="-6.604" y1="-0.254" x2="-6.096" y2="0.254" layer="51"/>
<rectangle x1="6.096" y1="-0.254" x2="6.604" y2="0.254" layer="51"/>
</package>
<package name="1X06M">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt; - 2MM"</description>
<wire x1="6.25" y1="1.25" x2="6.25" y2="-1.25" width="0.2032" layer="21"/>
<wire x1="6.25" y1="-1.25" x2="-6.25" y2="-1.25" width="0.2032" layer="21"/>
<wire x1="-6.25" y1="-1.25" x2="-6.25" y2="1.25" width="0.2032" layer="21"/>
<wire x1="-6.25" y1="1.25" x2="6.25" y2="1.25" width="0.2032" layer="21"/>
<pad name="1" x="-5" y="0" drill="0.9144" shape="square"/>
<pad name="2" x="-3" y="0" drill="0.9144"/>
<pad name="3" x="-1" y="0" drill="0.9144" rot="R270"/>
<pad name="4" x="1" y="0" drill="0.9144" rot="R270"/>
<pad name="5" x="3" y="0" drill="0.9144" rot="R270"/>
<pad name="6" x="5" y="0" drill="0.9144" rot="R270"/>
<text x="-7" y="-1" size="1.016" layer="25" ratio="14" rot="R90">&gt;NAME</text>
<text x="8" y="-1" size="0.8128" layer="27" ratio="10" rot="R90">&gt;VALUE</text>
<rectangle x1="-3.25" y1="-0.25" x2="-2.75" y2="0.25" layer="51"/>
<rectangle x1="-5.25" y1="-0.25" x2="-4.75" y2="0.25" layer="51"/>
<rectangle x1="0.75" y1="-0.25" x2="1.25" y2="0.25" layer="51" rot="R270"/>
<rectangle x1="-1.25" y1="-0.25" x2="-0.75" y2="0.25" layer="51" rot="R270"/>
<rectangle x1="4.75" y1="-0.25" x2="5.25" y2="0.25" layer="51" rot="R270"/>
<rectangle x1="2.75" y1="-0.25" x2="3.25" y2="0.25" layer="51" rot="R270"/>
</package>
</packages>
<symbols>
<symbol name="PINHD6">
<wire x1="-6.35" y1="-7.62" x2="1.27" y2="-7.62" width="0.4064" layer="94"/>
<wire x1="1.27" y1="-7.62" x2="1.27" y2="10.16" width="0.4064" layer="94"/>
<wire x1="1.27" y1="10.16" x2="-6.35" y2="10.16" width="0.4064" layer="94"/>
<wire x1="-6.35" y1="10.16" x2="-6.35" y2="-7.62" width="0.4064" layer="94"/>
<text x="-6.35" y="10.795" size="1.778" layer="95">&gt;NAME</text>
<text x="-6.35" y="-10.16" size="1.778" layer="96">&gt;VALUE</text>
<pin name="1" x="-2.54" y="7.62" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="2" x="-2.54" y="5.08" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="3" x="-2.54" y="2.54" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="4" x="-2.54" y="0" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="5" x="-2.54" y="-2.54" visible="pad" length="short" direction="pas" function="dot"/>
<pin name="6" x="-2.54" y="-5.08" visible="pad" length="short" direction="pas" function="dot"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="PINHD-1X6" prefix="JP" uservalue="yes">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<gates>
<gate name="A" symbol="PINHD6" x="0" y="-2.54"/>
</gates>
<devices>
<device name="" package="1X06">
<connects>
<connect gate="A" pin="1" pad="1"/>
<connect gate="A" pin="2" pad="2"/>
<connect gate="A" pin="3" pad="3"/>
<connect gate="A" pin="4" pad="4"/>
<connect gate="A" pin="5" pad="5"/>
<connect gate="A" pin="6" pad="6"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="M" package="1X06M">
<connects>
<connect gate="A" pin="1" pad="1"/>
<connect gate="A" pin="2" pad="2"/>
<connect gate="A" pin="3" pad="3"/>
<connect gate="A" pin="4" pad="4"/>
<connect gate="A" pin="5" pad="5"/>
<connect gate="A" pin="6" pad="6"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="supply2" urn="urn:adsk.eagle:library:372">
<description>&lt;b&gt;Supply Symbols&lt;/b&gt;&lt;p&gt;
GND, VCC, 0V, +5V, -5V, etc.&lt;p&gt;
Please keep in mind, that these devices are necessary for the
automatic wiring of the supply signals.&lt;p&gt;
The pin name defined in the symbol is identical to the net which is to be wired automatically.&lt;p&gt;
In this library the device names are the same as the pin names of the symbols, therefore the correct signal names appear next to the supply symbols in the schematic.&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
</packages>
<symbols>
<symbol name="GND" urn="urn:adsk.eagle:symbol:26990/1" library_version="2">
<wire x1="-1.27" y1="0" x2="1.27" y2="0" width="0.254" layer="94"/>
<wire x1="1.27" y1="0" x2="0" y2="-1.27" width="0.254" layer="94"/>
<wire x1="0" y1="-1.27" x2="-1.27" y2="0" width="0.254" layer="94"/>
<text x="-1.905" y="-3.175" size="1.778" layer="96">&gt;VALUE</text>
<pin name="GND" x="0" y="2.54" visible="off" length="short" direction="sup" rot="R270"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="GND" urn="urn:adsk.eagle:component:27037/1" prefix="SUPPLY" library_version="2">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="GND" symbol="GND" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="supply1" urn="urn:adsk.eagle:library:371">
<description>&lt;b&gt;Supply Symbols&lt;/b&gt;&lt;p&gt;
 GND, VCC, 0V, +5V, -5V, etc.&lt;p&gt;
 Please keep in mind, that these devices are necessary for the
 automatic wiring of the supply signals.&lt;p&gt;
 The pin name defined in the symbol is identical to the net which is to be wired automatically.&lt;p&gt;
 In this library the device names are the same as the pin names of the symbols, therefore the correct signal names appear next to the supply symbols in the schematic.&lt;p&gt;
 &lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
</packages>
<symbols>
<symbol name="VDD" urn="urn:adsk.eagle:symbol:26943/1" library_version="1">
<wire x1="1.27" y1="-1.905" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="-1.27" y2="-1.905" width="0.254" layer="94"/>
<wire x1="0" y1="1.27" x2="-1.27" y2="-1.905" width="0.254" layer="94"/>
<wire x1="1.27" y1="-1.905" x2="0" y2="1.27" width="0.254" layer="94"/>
<text x="-2.54" y="-2.54" size="1.778" layer="96" rot="R90">&gt;VALUE</text>
<pin name="VDD" x="0" y="-2.54" visible="off" length="short" direction="sup" rot="R90"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="VDD" urn="urn:adsk.eagle:component:26970/1" prefix="VDD" library_version="1">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="VDD" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="frames" urn="urn:adsk.eagle:library:229">
<description>&lt;b&gt;Frames for Sheet and Layout&lt;/b&gt;</description>
<packages>
</packages>
<symbols>
<symbol name="FRAME_A_L" urn="urn:adsk.eagle:symbol:13882/1" library_version="1">
<frame x1="0" y1="0" x2="279.4" y2="215.9" columns="6" rows="5" layer="94" border-bottom="no"/>
</symbol>
<symbol name="DOCFIELD" urn="urn:adsk.eagle:symbol:13864/1" library_version="1">
<wire x1="0" y1="0" x2="71.12" y2="0" width="0.1016" layer="94"/>
<wire x1="101.6" y1="15.24" x2="87.63" y2="15.24" width="0.1016" layer="94"/>
<wire x1="0" y1="0" x2="0" y2="5.08" width="0.1016" layer="94"/>
<wire x1="0" y1="5.08" x2="71.12" y2="5.08" width="0.1016" layer="94"/>
<wire x1="0" y1="5.08" x2="0" y2="15.24" width="0.1016" layer="94"/>
<wire x1="101.6" y1="15.24" x2="101.6" y2="5.08" width="0.1016" layer="94"/>
<wire x1="71.12" y1="5.08" x2="71.12" y2="0" width="0.1016" layer="94"/>
<wire x1="71.12" y1="5.08" x2="87.63" y2="5.08" width="0.1016" layer="94"/>
<wire x1="71.12" y1="0" x2="101.6" y2="0" width="0.1016" layer="94"/>
<wire x1="87.63" y1="15.24" x2="87.63" y2="5.08" width="0.1016" layer="94"/>
<wire x1="87.63" y1="15.24" x2="0" y2="15.24" width="0.1016" layer="94"/>
<wire x1="87.63" y1="5.08" x2="101.6" y2="5.08" width="0.1016" layer="94"/>
<wire x1="101.6" y1="5.08" x2="101.6" y2="0" width="0.1016" layer="94"/>
<wire x1="0" y1="15.24" x2="0" y2="22.86" width="0.1016" layer="94"/>
<wire x1="101.6" y1="35.56" x2="0" y2="35.56" width="0.1016" layer="94"/>
<wire x1="101.6" y1="35.56" x2="101.6" y2="22.86" width="0.1016" layer="94"/>
<wire x1="0" y1="22.86" x2="101.6" y2="22.86" width="0.1016" layer="94"/>
<wire x1="0" y1="22.86" x2="0" y2="35.56" width="0.1016" layer="94"/>
<wire x1="101.6" y1="22.86" x2="101.6" y2="15.24" width="0.1016" layer="94"/>
<text x="1.27" y="1.27" size="2.54" layer="94">Date:</text>
<text x="12.7" y="1.27" size="2.54" layer="94">&gt;LAST_DATE_TIME</text>
<text x="72.39" y="1.27" size="2.54" layer="94">Sheet:</text>
<text x="86.36" y="1.27" size="2.54" layer="94">&gt;SHEET</text>
<text x="88.9" y="11.43" size="2.54" layer="94">REV:</text>
<text x="1.27" y="19.05" size="2.54" layer="94">TITLE:</text>
<text x="1.27" y="11.43" size="2.54" layer="94">Document Number:</text>
<text x="17.78" y="19.05" size="2.54" layer="94">&gt;DRAWING_NAME</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="FRAME_A_L" urn="urn:adsk.eagle:component:13939/1" prefix="FRAME" uservalue="yes" library_version="1">
<description>&lt;b&gt;FRAME&lt;/b&gt; A Size , 8 1/2 x 11 INCH, Landscape&lt;p&gt;</description>
<gates>
<gate name="G$1" symbol="FRAME_A_L" x="0" y="0" addlevel="always"/>
<gate name="G$2" symbol="DOCFIELD" x="172.72" y="0" addlevel="always"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
<class number="1" name="Gnd" width="0" drill="0">
</class>
</classes>
<parts>
<part name="C1" library="2023-06-30_23-55-05_Library" deviceset="0402YC104KAT2A" device="0402_AVX" value=".01uF"/>
<part name="C2" library="2023-06-30_23-55-05_Library" deviceset="0402YC104KAT2A" device="0402_AVX" value=".01uF"/>
<part name="RN1" library="CAY16-332J4LF" deviceset="CAY16-332J4LF" device="" value="3.3K"/>
<part name="U1" library="untitled" deviceset="PHDC2021DEBT" device="DEB0006A_NV"/>
<part name="JP1" library="pinhead" deviceset="PINHD-1X6" device="M" value="J1"/>
<part name="U2" library="untitled" deviceset="PHDC2021DEBT" device="DEB0006A_NV"/>
<part name="SUPPLY1" library="supply2" library_urn="urn:adsk.eagle:library:372" deviceset="GND" device=""/>
<part name="SUPPLY2" library="supply2" library_urn="urn:adsk.eagle:library:372" deviceset="GND" device=""/>
<part name="SUPPLY3" library="supply2" library_urn="urn:adsk.eagle:library:372" deviceset="GND" device=""/>
<part name="SUPPLY4" library="supply2" library_urn="urn:adsk.eagle:library:372" deviceset="GND" device=""/>
<part name="VDD1" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="VDD" device=""/>
<part name="VDD2" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="VDD" device=""/>
<part name="VDD3" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="VDD" device=""/>
<part name="VDD4" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="VDD" device=""/>
<part name="SUPPLY5" library="supply2" library_urn="urn:adsk.eagle:library:372" deviceset="GND" device=""/>
<part name="FRAME1" library="frames" library_urn="urn:adsk.eagle:library:229" deviceset="FRAME_A_L" device="" value="F1"/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="C1" gate="A" x="180.34" y="127" smashed="yes">
<attribute name="VALUE" x="185.3469" y="129.0701" size="3.48" layer="96" ratio="10"/>
<attribute name="NAME" x="186.4152" y="134.1501" size="3.48" layer="95" ratio="10"/>
</instance>
<instance part="C2" gate="A" x="53.34" y="127" smashed="yes">
<attribute name="VALUE" x="58.3469" y="129.0701" size="3.48" layer="96" ratio="10"/>
<attribute name="NAME" x="59.4152" y="134.1501" size="3.48" layer="95" ratio="10"/>
</instance>
<instance part="RN1" gate="G$1" x="137.16" y="104.14" smashed="yes">
<attribute name="NAME" x="130.297559375" y="117.6035" size="2.54148125" layer="95"/>
<attribute name="VALUE" x="133.08603125" y="88.3854" size="2.54331875" layer="96"/>
</instance>
<instance part="U1" gate="A" x="71.12" y="109.22" smashed="yes">
<attribute name="NAME" x="81.6356" y="123.4186" size="2.0828" layer="95" ratio="6" rot="SR0"/>
<attribute name="VALUE" x="50.5206" y="92.9386" size="2.0828" layer="96" ratio="6" rot="SR0"/>
</instance>
<instance part="JP1" gate="A" x="139.7" y="142.24" smashed="yes">
<attribute name="NAME" x="133.35" y="153.035" size="1.778" layer="95"/>
<attribute name="VALUE" x="133.35" y="132.08" size="1.778" layer="96"/>
</instance>
<instance part="U2" gate="A" x="198.12" y="109.22" smashed="yes">
<attribute name="NAME" x="206.0956" y="123.4186" size="2.0828" layer="95" ratio="6" rot="SR0"/>
<attribute name="VALUE" x="177.5206" y="92.9386" size="2.0828" layer="96" ratio="6" rot="SR0"/>
</instance>
<instance part="SUPPLY1" gate="GND" x="93.98" y="91.44" smashed="yes">
<attribute name="VALUE" x="92.075" y="88.265" size="1.778" layer="96"/>
</instance>
<instance part="SUPPLY2" gate="GND" x="48.26" y="91.44" smashed="yes">
<attribute name="VALUE" x="46.355" y="88.265" size="1.778" layer="96"/>
</instance>
<instance part="SUPPLY3" gate="GND" x="175.26" y="91.44" smashed="yes">
<attribute name="VALUE" x="173.355" y="88.265" size="1.778" layer="96"/>
</instance>
<instance part="SUPPLY4" gate="GND" x="220.98" y="91.44" smashed="yes">
<attribute name="VALUE" x="219.075" y="88.265" size="1.778" layer="96"/>
</instance>
<instance part="VDD1" gate="G$1" x="43.18" y="134.62" smashed="yes">
<attribute name="VALUE" x="40.64" y="132.08" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="VDD2" gate="G$1" x="170.18" y="134.62" smashed="yes">
<attribute name="VALUE" x="167.64" y="132.08" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="VDD3" gate="G$1" x="154.94" y="119.38" smashed="yes">
<attribute name="VALUE" x="152.4" y="116.84" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="VDD4" gate="G$1" x="119.38" y="139.7" smashed="yes">
<attribute name="VALUE" x="116.84" y="137.16" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="SUPPLY5" gate="GND" x="119.38" y="147.32" smashed="yes">
<attribute name="VALUE" x="117.475" y="144.145" size="1.778" layer="96"/>
</instance>
<instance part="FRAME1" gate="G$1" x="0" y="0" smashed="yes"/>
<instance part="FRAME1" gate="G$2" x="172.72" y="0" smashed="yes">
<attribute name="LAST_DATE_TIME" x="185.42" y="1.27" size="2.54" layer="94"/>
<attribute name="SHEET" x="259.08" y="1.27" size="2.54" layer="94"/>
<attribute name="DRAWING_NAME" x="190.5" y="19.05" size="2.54" layer="94"/>
</instance>
</instances>
<busses>
</busses>
<nets>
<net name="SCL1" class="0">
<segment>
<pinref part="U1" gate="A" pin="SCL"/>
<wire x1="88.9" y1="116.84" x2="93.98" y2="116.84" width="0.1524" layer="91"/>
<label x="93.98" y="116.84" size="1.27" layer="95" xref="yes"/>
</segment>
<segment>
<pinref part="JP1" gate="A" pin="2"/>
<wire x1="137.16" y1="147.32" x2="129.54" y2="147.32" width="0.1524" layer="91"/>
<label x="129.54" y="147.32" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
<segment>
<pinref part="RN1" gate="G$1" pin="4"/>
<wire x1="127" y1="96.52" x2="124.46" y2="96.52" width="0.1524" layer="91"/>
<label x="124.46" y="96.52" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="SDA1" class="0">
<segment>
<pinref part="U1" gate="A" pin="SDA"/>
<wire x1="88.9" y1="114.3" x2="93.98" y2="114.3" width="0.1524" layer="91"/>
<label x="93.98" y="114.3" size="1.27" layer="95" xref="yes"/>
</segment>
<segment>
<pinref part="JP1" gate="A" pin="3"/>
<wire x1="137.16" y1="144.78" x2="129.54" y2="144.78" width="0.1524" layer="91"/>
<label x="129.54" y="144.78" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
<segment>
<pinref part="RN1" gate="G$1" pin="3"/>
<wire x1="127" y1="101.6" x2="124.46" y2="101.6" width="0.1524" layer="91"/>
<label x="124.46" y="101.6" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="GND" class="0">
<segment>
<pinref part="U1" gate="A" pin="DRDY_INT"/>
<wire x1="88.9" y1="109.22" x2="93.98" y2="109.22" width="0.1524" layer="91"/>
<wire x1="93.98" y1="109.22" x2="93.98" y2="104.14" width="0.1524" layer="91"/>
<pinref part="U1" gate="A" pin="GND"/>
<wire x1="93.98" y1="104.14" x2="93.98" y2="99.06" width="0.1524" layer="91"/>
<wire x1="93.98" y1="99.06" x2="93.98" y2="93.98" width="0.1524" layer="91"/>
<wire x1="88.9" y1="99.06" x2="93.98" y2="99.06" width="0.1524" layer="91"/>
<junction x="93.98" y="99.06"/>
<pinref part="U1" gate="A" pin="PAD"/>
<wire x1="88.9" y1="104.14" x2="93.98" y2="104.14" width="0.1524" layer="91"/>
<junction x="93.98" y="104.14"/>
<pinref part="SUPPLY1" gate="GND" pin="GND"/>
<wire x1="93.98" y1="99.06" x2="104.14" y2="99.06" width="0.1524" layer="91"/>
<wire x1="104.14" y1="99.06" x2="104.14" y2="127" width="0.1524" layer="91"/>
<pinref part="C2" gate="A" pin="2"/>
<wire x1="104.14" y1="127" x2="60.96" y2="127" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="U1" gate="A" pin="ADDR"/>
<wire x1="53.34" y1="106.68" x2="48.26" y2="106.68" width="0.1524" layer="91"/>
<wire x1="48.26" y1="106.68" x2="48.26" y2="93.98" width="0.1524" layer="91"/>
<pinref part="SUPPLY2" gate="GND" pin="GND"/>
</segment>
<segment>
<pinref part="U2" gate="A" pin="ADDR"/>
<wire x1="180.34" y1="106.68" x2="175.26" y2="106.68" width="0.1524" layer="91"/>
<wire x1="175.26" y1="106.68" x2="175.26" y2="93.98" width="0.1524" layer="91"/>
<pinref part="SUPPLY3" gate="GND" pin="GND"/>
</segment>
<segment>
<pinref part="U2" gate="A" pin="GND"/>
<wire x1="215.9" y1="99.06" x2="220.98" y2="99.06" width="0.1524" layer="91"/>
<wire x1="220.98" y1="99.06" x2="220.98" y2="93.98" width="0.1524" layer="91"/>
<pinref part="U2" gate="A" pin="DRDY_INT"/>
<wire x1="220.98" y1="99.06" x2="220.98" y2="104.14" width="0.1524" layer="91"/>
<wire x1="220.98" y1="104.14" x2="220.98" y2="109.22" width="0.1524" layer="91"/>
<wire x1="220.98" y1="109.22" x2="215.9" y2="109.22" width="0.1524" layer="91"/>
<junction x="220.98" y="99.06"/>
<pinref part="U2" gate="A" pin="PAD"/>
<wire x1="215.9" y1="104.14" x2="220.98" y2="104.14" width="0.1524" layer="91"/>
<junction x="220.98" y="104.14"/>
<pinref part="SUPPLY4" gate="GND" pin="GND"/>
<wire x1="220.98" y1="99.06" x2="231.14" y2="99.06" width="0.1524" layer="91"/>
<wire x1="231.14" y1="99.06" x2="231.14" y2="127" width="0.1524" layer="91"/>
<pinref part="C1" gate="A" pin="2"/>
<wire x1="231.14" y1="127" x2="187.96" y2="127" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="JP1" gate="A" pin="1"/>
<wire x1="137.16" y1="149.86" x2="119.38" y2="149.86" width="0.1524" layer="91"/>
<pinref part="SUPPLY5" gate="GND" pin="GND"/>
</segment>
</net>
<net name="VDD" class="0">
<segment>
<pinref part="U1" gate="A" pin="VDD"/>
<wire x1="53.34" y1="116.84" x2="50.8" y2="116.84" width="0.1524" layer="91"/>
<pinref part="C2" gate="A" pin="1"/>
<wire x1="50.8" y1="116.84" x2="50.8" y2="127" width="0.1524" layer="91"/>
<wire x1="50.8" y1="127" x2="53.34" y2="127" width="0.1524" layer="91"/>
<wire x1="50.8" y1="127" x2="43.18" y2="127" width="0.1524" layer="91"/>
<junction x="50.8" y="127"/>
<wire x1="43.18" y1="127" x2="43.18" y2="132.08" width="0.1524" layer="91"/>
<pinref part="VDD1" gate="G$1" pin="VDD"/>
</segment>
<segment>
<pinref part="U2" gate="A" pin="VDD"/>
<wire x1="180.34" y1="116.84" x2="177.8" y2="116.84" width="0.1524" layer="91"/>
<wire x1="177.8" y1="116.84" x2="177.8" y2="127" width="0.1524" layer="91"/>
<wire x1="177.8" y1="127" x2="180.34" y2="127" width="0.1524" layer="91"/>
<wire x1="177.8" y1="127" x2="170.18" y2="127" width="0.1524" layer="91"/>
<junction x="177.8" y="127"/>
<wire x1="170.18" y1="127" x2="170.18" y2="132.08" width="0.1524" layer="91"/>
<pinref part="C1" gate="A" pin="1"/>
<pinref part="VDD2" gate="G$1" pin="VDD"/>
</segment>
<segment>
<pinref part="RN1" gate="G$1" pin="5"/>
<wire x1="147.32" y1="96.52" x2="154.94" y2="96.52" width="0.1524" layer="91"/>
<wire x1="154.94" y1="96.52" x2="154.94" y2="101.6" width="0.1524" layer="91"/>
<pinref part="RN1" gate="G$1" pin="6"/>
<wire x1="154.94" y1="101.6" x2="154.94" y2="106.68" width="0.1524" layer="91"/>
<wire x1="154.94" y1="106.68" x2="154.94" y2="111.76" width="0.1524" layer="91"/>
<wire x1="154.94" y1="111.76" x2="154.94" y2="116.84" width="0.1524" layer="91"/>
<wire x1="147.32" y1="101.6" x2="154.94" y2="101.6" width="0.1524" layer="91"/>
<junction x="154.94" y="101.6"/>
<pinref part="RN1" gate="G$1" pin="7"/>
<wire x1="147.32" y1="106.68" x2="154.94" y2="106.68" width="0.1524" layer="91"/>
<junction x="154.94" y="106.68"/>
<pinref part="RN1" gate="G$1" pin="8"/>
<wire x1="147.32" y1="111.76" x2="154.94" y2="111.76" width="0.1524" layer="91"/>
<junction x="154.94" y="111.76"/>
<pinref part="VDD3" gate="G$1" pin="VDD"/>
</segment>
<segment>
<pinref part="JP1" gate="A" pin="6"/>
<wire x1="119.38" y1="137.16" x2="137.16" y2="137.16" width="0.1524" layer="91"/>
<pinref part="VDD4" gate="G$1" pin="VDD"/>
</segment>
</net>
<net name="SCL2" class="0">
<segment>
<pinref part="U2" gate="A" pin="SCL"/>
<wire x1="215.9" y1="116.84" x2="220.98" y2="116.84" width="0.1524" layer="91"/>
<label x="220.98" y="116.84" size="1.27" layer="95" xref="yes"/>
</segment>
<segment>
<pinref part="JP1" gate="A" pin="4"/>
<wire x1="137.16" y1="142.24" x2="129.54" y2="142.24" width="0.1524" layer="91"/>
<label x="129.54" y="142.24" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
<segment>
<pinref part="RN1" gate="G$1" pin="2"/>
<wire x1="127" y1="106.68" x2="124.46" y2="106.68" width="0.1524" layer="91"/>
<label x="124.46" y="106.68" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="SDA2" class="0">
<segment>
<pinref part="U2" gate="A" pin="SDA"/>
<wire x1="215.9" y1="114.3" x2="220.98" y2="114.3" width="0.1524" layer="91"/>
<label x="220.98" y="114.3" size="1.27" layer="95" xref="yes"/>
</segment>
<segment>
<pinref part="JP1" gate="A" pin="5"/>
<wire x1="137.16" y1="139.7" x2="129.54" y2="139.7" width="0.1524" layer="91"/>
<label x="129.54" y="139.7" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
<segment>
<pinref part="RN1" gate="G$1" pin="1"/>
<wire x1="127" y1="111.76" x2="124.46" y2="111.76" width="0.1524" layer="91"/>
<label x="124.46" y="111.76" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
<errors>
<approved hash="104,1,53.34,106.68,U1,ADDR,GND,,,"/>
<approved hash="104,1,88.9,109.22,U1,DRDY_INT,GND,,,"/>
<approved hash="104,1,88.9,104.14,U1,PAD,GND,,,"/>
<approved hash="104,1,180.34,106.68,U2,ADDR,GND,,,"/>
<approved hash="104,1,215.9,109.22,U2,DRDY_INT,GND,,,"/>
<approved hash="104,1,215.9,104.14,U2,PAD,GND,,,"/>
</errors>
</schematic>
</drawing>
<compatibility>
<note version="8.2" severity="warning">
Since Version 8.2, EAGLE supports online libraries. The ids
of those online libraries will not be understood (or retained)
with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports URNs for individual library
assets (packages, symbols, and devices). The URNs of those assets
will not be understood (or retained) with this version.
</note>
</compatibility>
</eagle>
