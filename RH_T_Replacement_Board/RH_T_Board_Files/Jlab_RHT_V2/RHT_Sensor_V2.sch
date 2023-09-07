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
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="08055C104KAT4A">
<packages>
<package name="CAPC2012X94N">
<text x="-1.71" y="-1.07" size="0.5" layer="27" align="top-left">&gt;VALUE</text>
<text x="-1.71" y="1.07" size="0.5" layer="25">&gt;NAME</text>
<wire x1="1.1" y1="-0.72" x2="-1.1" y2="-0.72" width="0.127" layer="51"/>
<wire x1="1.1" y1="0.72" x2="-1.1" y2="0.72" width="0.127" layer="51"/>
<wire x1="1.1" y1="-0.72" x2="1.1" y2="0.72" width="0.127" layer="51"/>
<wire x1="-1.1" y1="-0.72" x2="-1.1" y2="0.72" width="0.127" layer="51"/>
<wire x1="-1.713" y1="-0.983" x2="1.713" y2="-0.983" width="0.05" layer="39"/>
<wire x1="-1.713" y1="0.983" x2="1.713" y2="0.983" width="0.05" layer="39"/>
<wire x1="-1.713" y1="-0.983" x2="-1.713" y2="0.983" width="0.05" layer="39"/>
<wire x1="1.713" y1="-0.983" x2="1.713" y2="0.983" width="0.05" layer="39"/>
<smd name="1" x="-0.88" y="0" dx="1.16" dy="1.47" layer="1"/>
<smd name="2" x="0.88" y="0" dx="1.16" dy="1.47" layer="1"/>
</package>
</packages>
<symbols>
<symbol name="08055C104KAT4A">
<text x="0" y="3.81093125" size="1.77843125" layer="95">&gt;NAME</text>
<text x="0" y="-5.08848125" size="1.78096875" layer="96">&gt;VALUE</text>
<rectangle x1="0" y1="-1.906859375" x2="0.635" y2="1.905" layer="94"/>
<rectangle x1="1.90685" y1="-1.90685" x2="2.54" y2="1.905" layer="94"/>
<pin name="2" x="5.08" y="0" visible="pad" length="short" direction="pas" rot="R180"/>
<pin name="1" x="-2.54" y="0" visible="pad" length="short" direction="pas"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="08055C104KAT4A" prefix="C">
<description>.1UF 50V 10% 0805 </description>
<gates>
<gate name="G$1" symbol="08055C104KAT4A" x="0" y="0"/>
</gates>
<devices>
<device name="" package="CAPC2012X94N">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name="">
<attribute name="DESCRIPTION" value=" 0.1 µF ±10% 50V Ceramic Capacitor X7R 0805 (2012 Metric) "/>
<attribute name="DIGIKEY_PART_NUMBER" value=""/>
<attribute name="MF" value="AVX"/>
<attribute name="MP" value="08055C104KAT4A"/>
<attribute name="PACKAGE" value="2012 AVX"/>
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
<library name="frames" urn="urn:adsk.eagle:library:229">
<description>&lt;b&gt;Frames for Sheet and Layout&lt;/b&gt;</description>
<packages>
</packages>
<symbols>
<symbol name="A3L-LOC" urn="urn:adsk.eagle:symbol:13881/1" library_version="1">
<wire x1="288.29" y1="3.81" x2="342.265" y2="3.81" width="0.1016" layer="94"/>
<wire x1="342.265" y1="3.81" x2="373.38" y2="3.81" width="0.1016" layer="94"/>
<wire x1="373.38" y1="3.81" x2="383.54" y2="3.81" width="0.1016" layer="94"/>
<wire x1="383.54" y1="3.81" x2="383.54" y2="8.89" width="0.1016" layer="94"/>
<wire x1="383.54" y1="8.89" x2="383.54" y2="13.97" width="0.1016" layer="94"/>
<wire x1="383.54" y1="13.97" x2="383.54" y2="19.05" width="0.1016" layer="94"/>
<wire x1="383.54" y1="19.05" x2="383.54" y2="24.13" width="0.1016" layer="94"/>
<wire x1="288.29" y1="3.81" x2="288.29" y2="24.13" width="0.1016" layer="94"/>
<wire x1="288.29" y1="24.13" x2="342.265" y2="24.13" width="0.1016" layer="94"/>
<wire x1="342.265" y1="24.13" x2="383.54" y2="24.13" width="0.1016" layer="94"/>
<wire x1="373.38" y1="3.81" x2="373.38" y2="8.89" width="0.1016" layer="94"/>
<wire x1="373.38" y1="8.89" x2="383.54" y2="8.89" width="0.1016" layer="94"/>
<wire x1="373.38" y1="8.89" x2="342.265" y2="8.89" width="0.1016" layer="94"/>
<wire x1="342.265" y1="8.89" x2="342.265" y2="3.81" width="0.1016" layer="94"/>
<wire x1="342.265" y1="8.89" x2="342.265" y2="13.97" width="0.1016" layer="94"/>
<wire x1="342.265" y1="13.97" x2="383.54" y2="13.97" width="0.1016" layer="94"/>
<wire x1="342.265" y1="13.97" x2="342.265" y2="19.05" width="0.1016" layer="94"/>
<wire x1="342.265" y1="19.05" x2="383.54" y2="19.05" width="0.1016" layer="94"/>
<wire x1="342.265" y1="19.05" x2="342.265" y2="24.13" width="0.1016" layer="94"/>
<text x="344.17" y="15.24" size="2.54" layer="94">&gt;DRAWING_NAME</text>
<text x="344.17" y="10.16" size="2.286" layer="94">&gt;LAST_DATE_TIME</text>
<text x="357.505" y="5.08" size="2.54" layer="94">&gt;SHEET</text>
<text x="343.916" y="4.953" size="2.54" layer="94">Sheet:</text>
<frame x1="0" y1="0" x2="387.35" y2="260.35" columns="8" rows="5" layer="94"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="A3L-LOC" urn="urn:adsk.eagle:component:13942/1" prefix="FRAME" uservalue="yes" library_version="1">
<description>&lt;b&gt;FRAME&lt;/b&gt;&lt;p&gt;
DIN A3, landscape with location and doc. field</description>
<gates>
<gate name="G$1" symbol="A3L-LOC" x="0" y="0"/>
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
<library name="One_mm_01x12">
<packages>
<package name="1MM_HEADER_01X12">
<pad name="P$1" x="0" y="0" drill="0.3" diameter="0.6" rot="R90"/>
<pad name="P$2" x="1" y="0" drill="0.3" diameter="0.6" rot="R90"/>
<pad name="P$3" x="2" y="0" drill="0.3" diameter="0.6" rot="R90"/>
<pad name="P$4" x="3" y="0" drill="0.3" diameter="0.6" rot="R90"/>
<pad name="P$5" x="4" y="0" drill="0.3" diameter="0.6" rot="R90"/>
<pad name="P$6" x="5" y="0" drill="0.3" diameter="0.6" rot="R90"/>
<pad name="P$7" x="6" y="0" drill="0.3" diameter="0.6" rot="R90"/>
<pad name="P$8" x="7" y="0" drill="0.3" diameter="0.6" rot="R90"/>
<pad name="P$9" x="8" y="0" drill="0.3" diameter="0.6" rot="R90"/>
<pad name="P$10" x="9" y="0" drill="0.3" diameter="0.6" rot="R90"/>
<pad name="P$11" x="10" y="0" drill="0.3" diameter="0.6" rot="R90"/>
<pad name="P$12" x="11" y="0" drill="0.3" diameter="0.6" rot="R90"/>
<wire x1="-0.75" y1="0.5" x2="-0.75" y2="-0.5" width="0.127" layer="21"/>
<wire x1="-0.75" y1="-0.5" x2="11.5" y2="-0.5" width="0.127" layer="21"/>
<wire x1="11.5" y1="-0.5" x2="11.5" y2="0.5" width="0.127" layer="21"/>
<wire x1="11.5" y1="0.5" x2="-0.75" y2="0.5" width="0.127" layer="21"/>
<text x="-0.5" y="0.75" size="1.27" layer="25">&gt;NAME</text>
<text x="-0.25" y="-2" size="1.27" layer="27">&gt;VALUE</text>
<dimension x1="0" y1="0" x2="1" y2="0" x3="0.5" y3="-6" textsize="1.27" layer="47"/>
</package>
</packages>
<symbols>
<symbol name="1MM_HEADER_01X12">
<wire x1="0" y1="0" x2="0" y2="-33.02" width="0.254" layer="94"/>
<wire x1="0" y1="-33.02" x2="5.08" y2="-33.02" width="0.254" layer="94"/>
<wire x1="5.08" y1="-33.02" x2="5.08" y2="0" width="0.254" layer="94"/>
<wire x1="5.08" y1="0" x2="0" y2="0" width="0.254" layer="94"/>
<pin name="TH0" x="-5.08" y="-2.54" length="middle"/>
<pin name="TH1" x="-5.08" y="-5.08" length="middle"/>
<pin name="TH2" x="-5.08" y="-7.62" length="middle"/>
<pin name="TH3" x="-5.08" y="-10.16" length="middle"/>
<pin name="TH4" x="-5.08" y="-12.7" length="middle"/>
<pin name="TH5" x="-5.08" y="-15.24" length="middle"/>
<pin name="TH6" x="-5.08" y="-17.78" length="middle"/>
<pin name="TH7" x="-5.08" y="-20.32" length="middle"/>
<pin name="TH8" x="-5.08" y="-22.86" length="middle"/>
<pin name="TH9" x="-5.08" y="-25.4" length="middle"/>
<pin name="TH10" x="-5.08" y="-27.94" length="middle"/>
<pin name="TH11" x="-5.08" y="-30.48" length="middle"/>
<text x="0" y="2.54" size="1.778" layer="95">&gt;NAME</text>
<text x="7.62" y="0" size="1.778" layer="96">&gt;VALUE</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="1MM_HEADER-01X12" prefix="TH" uservalue="yes">
<gates>
<gate name="G$1" symbol="1MM_HEADER_01X12" x="0" y="0"/>
</gates>
<devices>
<device name="" package="1MM_HEADER_01X12">
<connects>
<connect gate="G$1" pin="TH0" pad="P$1"/>
<connect gate="G$1" pin="TH1" pad="P$2"/>
<connect gate="G$1" pin="TH10" pad="P$11"/>
<connect gate="G$1" pin="TH11" pad="P$12"/>
<connect gate="G$1" pin="TH2" pad="P$3"/>
<connect gate="G$1" pin="TH3" pad="P$4"/>
<connect gate="G$1" pin="TH4" pad="P$5"/>
<connect gate="G$1" pin="TH5" pad="P$6"/>
<connect gate="G$1" pin="TH6" pad="P$7"/>
<connect gate="G$1" pin="TH7" pad="P$8"/>
<connect gate="G$1" pin="TH8" pad="P$9"/>
<connect gate="G$1" pin="TH9" pad="P$10"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="pinhead">
<description>&lt;b&gt;Pin Header Connectors&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="1X06" urn="urn:adsk.eagle:footprint:22361/1" locally_modified="yes">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<pad name="1" x="-6.35" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="2" x="-3.81" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="3" x="-1.27" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="4" x="1.27" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="5" x="3.81" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="6" x="6.35" y="0" drill="1.016" shape="long" rot="R90"/>
<text x="-7.6962" y="1.8288" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-7.62" y="-3.175" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="3.556" y1="-0.254" x2="4.064" y2="0.254" layer="51"/>
<rectangle x1="1.016" y1="-0.254" x2="1.524" y2="0.254" layer="51"/>
<rectangle x1="-1.524" y1="-0.254" x2="-1.016" y2="0.254" layer="51"/>
<rectangle x1="-4.064" y1="-0.254" x2="-3.556" y2="0.254" layer="51"/>
<rectangle x1="-6.604" y1="-0.254" x2="-6.096" y2="0.254" layer="51"/>
<rectangle x1="6.096" y1="-0.254" x2="6.604" y2="0.254" layer="51"/>
</package>
<package name="1X06/90" urn="urn:adsk.eagle:footprint:22362/1">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="-7.62" y1="-1.905" x2="-5.08" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="-1.905" x2="-5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="0.635" x2="-7.62" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="0.635" x2="-7.62" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-6.35" y1="6.985" x2="-6.35" y2="1.27" width="0.762" layer="21"/>
<wire x1="-5.08" y1="-1.905" x2="-2.54" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="-1.905" x2="-2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="0.635" x2="-5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="6.985" x2="-3.81" y2="1.27" width="0.762" layer="21"/>
<wire x1="-2.54" y1="-1.905" x2="0" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="0" y1="-1.905" x2="0" y2="0.635" width="0.1524" layer="21"/>
<wire x1="0" y1="0.635" x2="-2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="6.985" x2="-1.27" y2="1.27" width="0.762" layer="21"/>
<wire x1="0" y1="-1.905" x2="2.54" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="2.54" y1="-1.905" x2="2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="2.54" y1="0.635" x2="0" y2="0.635" width="0.1524" layer="21"/>
<wire x1="1.27" y1="6.985" x2="1.27" y2="1.27" width="0.762" layer="21"/>
<wire x1="2.54" y1="-1.905" x2="5.08" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="5.08" y1="-1.905" x2="5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="5.08" y1="0.635" x2="2.54" y2="0.635" width="0.1524" layer="21"/>
<wire x1="3.81" y1="6.985" x2="3.81" y2="1.27" width="0.762" layer="21"/>
<wire x1="5.08" y1="-1.905" x2="7.62" y2="-1.905" width="0.1524" layer="21"/>
<wire x1="7.62" y1="-1.905" x2="7.62" y2="0.635" width="0.1524" layer="21"/>
<wire x1="7.62" y1="0.635" x2="5.08" y2="0.635" width="0.1524" layer="21"/>
<wire x1="6.35" y1="6.985" x2="6.35" y2="1.27" width="0.762" layer="21"/>
<pad name="1" x="-6.35" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="2" x="-3.81" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="3" x="-1.27" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="4" x="1.27" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="5" x="3.81" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<pad name="6" x="6.35" y="-3.81" drill="1.016" shape="long" rot="R90"/>
<text x="-8.255" y="-3.81" size="1.27" layer="25" ratio="10" rot="R90">&gt;NAME</text>
<text x="9.525" y="-3.81" size="1.27" layer="27" rot="R90">&gt;VALUE</text>
<rectangle x1="-6.731" y1="0.635" x2="-5.969" y2="1.143" layer="21"/>
<rectangle x1="-4.191" y1="0.635" x2="-3.429" y2="1.143" layer="21"/>
<rectangle x1="-1.651" y1="0.635" x2="-0.889" y2="1.143" layer="21"/>
<rectangle x1="0.889" y1="0.635" x2="1.651" y2="1.143" layer="21"/>
<rectangle x1="3.429" y1="0.635" x2="4.191" y2="1.143" layer="21"/>
<rectangle x1="5.969" y1="0.635" x2="6.731" y2="1.143" layer="21"/>
<rectangle x1="-6.731" y1="-2.921" x2="-5.969" y2="-1.905" layer="21"/>
<rectangle x1="-4.191" y1="-2.921" x2="-3.429" y2="-1.905" layer="21"/>
<rectangle x1="-1.651" y1="-2.921" x2="-0.889" y2="-1.905" layer="21"/>
<rectangle x1="0.889" y1="-2.921" x2="1.651" y2="-1.905" layer="21"/>
<rectangle x1="3.429" y1="-2.921" x2="4.191" y2="-1.905" layer="21"/>
<rectangle x1="5.969" y1="-2.921" x2="6.731" y2="-1.905" layer="21"/>
</package>
</packages>
<packages3d>
<package3d name="1X06" urn="urn:adsk.eagle:package:22472/2" type="model">
<description>PIN HEADER</description>
<packageinstances>
<packageinstance name="1X06"/>
</packageinstances>
</package3d>
<package3d name="1X06/90" urn="urn:adsk.eagle:package:22475/2" type="model">
<description>PIN HEADER</description>
<packageinstances>
<packageinstance name="1X06/90"/>
</packageinstances>
</package3d>
</packages3d>
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
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:22472/2"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="79" constant="no"/>
</technology>
</technologies>
</device>
<device name="/90" package="1X06/90">
<connects>
<connect gate="A" pin="1" pad="1"/>
<connect gate="A" pin="2" pad="2"/>
<connect gate="A" pin="3" pad="3"/>
<connect gate="A" pin="4" pad="4"/>
<connect gate="A" pin="5" pad="5"/>
<connect gate="A" pin="6" pad="6"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:22475/2"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="10" constant="no"/>
</technology>
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
</classes>
<parts>
<part name="C1" library="08055C104KAT4A" deviceset="08055C104KAT4A" device="" value="0.1uF"/>
<part name="C2" library="08055C104KAT4A" deviceset="08055C104KAT4A" device="" value="0.1uF"/>
<part name="RN1" library="CAY16-332J4LF" deviceset="CAY16-332J4LF" device="" value="3.3K"/>
<part name="U1" library="untitled" deviceset="PHDC2021DEBT" device="DEB0006A_NV"/>
<part name="U2" library="untitled" deviceset="PHDC2021DEBT" device="DEB0006A_NV"/>
<part name="VDD2" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="VDD" device=""/>
<part name="VDD3" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="VDD" device=""/>
<part name="VDD4" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="VDD" device=""/>
<part name="SUPPLY1" library="supply2" library_urn="urn:adsk.eagle:library:372" deviceset="GND" device=""/>
<part name="SUPPLY3" library="supply2" library_urn="urn:adsk.eagle:library:372" deviceset="GND" device=""/>
<part name="SUPPLY5" library="supply2" library_urn="urn:adsk.eagle:library:372" deviceset="GND" device=""/>
<part name="SUPPLY4" library="supply2" library_urn="urn:adsk.eagle:library:372" deviceset="GND" device=""/>
<part name="FRAME1" library="frames" library_urn="urn:adsk.eagle:library:229" deviceset="A3L-LOC" device="" value="F1"/>
<part name="VDD1" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="VDD" device=""/>
<part name="SUPPLY2" library="supply2" library_urn="urn:adsk.eagle:library:372" deviceset="GND" device=""/>
<part name="TH1" library="One_mm_01x12" deviceset="1MM_HEADER-01X12" device="" value="TH1"/>
<part name="JP1" library="pinhead" deviceset="PINHD-1X6" device="" package3d_urn="urn:adsk.eagle:package:22472/2" value="J1"/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="C1" gate="G$1" x="114.3" y="121.92" smashed="yes">
<attribute name="NAME" x="114.3" y="125.73093125" size="1.77843125" layer="95"/>
<attribute name="VALUE" x="119.38" y="119.37151875" size="1.78096875" layer="96"/>
</instance>
<instance part="C2" gate="G$1" x="243.84" y="121.92" smashed="yes">
<attribute name="NAME" x="246.38" y="125.73093125" size="1.77843125" layer="95"/>
<attribute name="VALUE" x="248.92" y="119.37151875" size="1.78096875" layer="96"/>
</instance>
<instance part="RN1" gate="G$1" x="200.66" y="106.68" smashed="yes">
<attribute name="NAME" x="193.797559375" y="120.1435" size="2.54148125" layer="95"/>
<attribute name="VALUE" x="196.58603125" y="90.9254" size="2.54331875" layer="96"/>
</instance>
<instance part="U1" gate="A" x="129.54" y="104.14" smashed="yes">
<attribute name="NAME" x="127.3556" y="113.2586" size="2.0828" layer="95" ratio="6" rot="SR0"/>
<attribute name="VALUE" x="108.9406" y="87.8586" size="2.0828" layer="96" ratio="6" rot="SR0"/>
</instance>
<instance part="U2" gate="A" x="259.08" y="104.14" smashed="yes">
<attribute name="NAME" x="256.8956" y="113.2586" size="2.0828" layer="95" ratio="6" rot="SR0"/>
<attribute name="VALUE" x="238.4806" y="87.8586" size="2.0828" layer="96" ratio="6" rot="SR0"/>
</instance>
<instance part="VDD2" gate="G$1" x="213.36" y="121.92" smashed="yes">
<attribute name="VALUE" x="210.82" y="119.38" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="VDD3" gate="G$1" x="233.68" y="127" smashed="yes">
<attribute name="VALUE" x="231.14" y="124.46" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="VDD4" gate="G$1" x="104.14" y="127" smashed="yes">
<attribute name="VALUE" x="101.6" y="124.46" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="SUPPLY1" gate="GND" x="106.68" y="86.36" smashed="yes">
<attribute name="VALUE" x="104.775" y="83.185" size="1.778" layer="96"/>
</instance>
<instance part="SUPPLY3" gate="GND" x="152.4" y="86.36" smashed="yes">
<attribute name="VALUE" x="150.495" y="83.185" size="1.778" layer="96"/>
</instance>
<instance part="SUPPLY5" gate="GND" x="281.94" y="86.36" smashed="yes">
<attribute name="VALUE" x="280.035" y="83.185" size="1.778" layer="96"/>
</instance>
<instance part="SUPPLY4" gate="GND" x="236.22" y="86.36" smashed="yes">
<attribute name="VALUE" x="234.315" y="83.185" size="1.778" layer="96"/>
</instance>
<instance part="FRAME1" gate="G$1" x="0" y="0" smashed="yes">
<attribute name="DRAWING_NAME" x="344.17" y="15.24" size="2.54" layer="94"/>
<attribute name="LAST_DATE_TIME" x="344.17" y="10.16" size="2.286" layer="94"/>
<attribute name="SHEET" x="357.505" y="5.08" size="2.54" layer="94"/>
</instance>
<instance part="VDD1" gate="G$1" x="218.44" y="162.56" smashed="yes">
<attribute name="VALUE" x="215.9" y="160.02" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="SUPPLY2" gate="GND" x="218.44" y="137.16" smashed="yes">
<attribute name="VALUE" x="219.075" y="133.985" size="1.778" layer="96"/>
</instance>
<instance part="TH1" gate="G$1" x="170.18" y="165.1" smashed="yes">
<attribute name="NAME" x="170.18" y="167.64" size="1.778" layer="95"/>
<attribute name="VALUE" x="177.8" y="165.1" size="1.778" layer="96"/>
</instance>
<instance part="JP1" gate="A" x="208.28" y="149.86" smashed="yes" rot="R180">
<attribute name="NAME" x="214.63" y="139.065" size="1.778" layer="95" rot="R180"/>
<attribute name="VALUE" x="214.63" y="160.02" size="1.778" layer="96" rot="R180"/>
</instance>
</instances>
<busses>
</busses>
<nets>
<net name="VDD" class="0">
<segment>
<pinref part="U1" gate="A" pin="VDD"/>
<wire x1="111.76" y1="111.76" x2="104.14" y2="111.76" width="0.1524" layer="91"/>
<pinref part="VDD4" gate="G$1" pin="VDD"/>
<wire x1="104.14" y1="111.76" x2="104.14" y2="121.92" width="0.1524" layer="91"/>
<wire x1="104.14" y1="121.92" x2="104.14" y2="124.46" width="0.1524" layer="91"/>
<wire x1="104.14" y1="121.92" x2="111.76" y2="121.92" width="0.1524" layer="91"/>
<junction x="104.14" y="121.92"/>
<pinref part="C1" gate="G$1" pin="1"/>
</segment>
<segment>
<pinref part="VDD3" gate="G$1" pin="VDD"/>
<wire x1="233.68" y1="124.46" x2="233.68" y2="121.92" width="0.1524" layer="91"/>
<pinref part="U2" gate="A" pin="VDD"/>
<wire x1="233.68" y1="121.92" x2="233.68" y2="111.76" width="0.1524" layer="91"/>
<wire x1="233.68" y1="111.76" x2="241.3" y2="111.76" width="0.1524" layer="91"/>
<wire x1="233.68" y1="121.92" x2="241.3" y2="121.92" width="0.1524" layer="91"/>
<junction x="233.68" y="121.92"/>
<pinref part="C2" gate="G$1" pin="1"/>
</segment>
<segment>
<wire x1="210.82" y1="154.94" x2="218.44" y2="154.94" width="0.1524" layer="91"/>
<wire x1="218.44" y1="154.94" x2="218.44" y2="160.02" width="0.1524" layer="91"/>
<pinref part="VDD1" gate="G$1" pin="VDD"/>
<pinref part="JP1" gate="A" pin="6"/>
</segment>
<segment>
<pinref part="RN1" gate="G$1" pin="8"/>
<wire x1="210.82" y1="114.3" x2="213.36" y2="114.3" width="0.1524" layer="91"/>
<pinref part="VDD2" gate="G$1" pin="VDD"/>
<wire x1="213.36" y1="119.38" x2="213.36" y2="114.3" width="0.1524" layer="91"/>
<pinref part="RN1" gate="G$1" pin="7"/>
<wire x1="210.82" y1="109.22" x2="213.36" y2="109.22" width="0.1524" layer="91"/>
<wire x1="213.36" y1="114.3" x2="213.36" y2="109.22" width="0.1524" layer="91"/>
<junction x="213.36" y="114.3"/>
<pinref part="RN1" gate="G$1" pin="6"/>
<wire x1="210.82" y1="104.14" x2="213.36" y2="104.14" width="0.1524" layer="91"/>
<wire x1="213.36" y1="109.22" x2="213.36" y2="104.14" width="0.1524" layer="91"/>
<junction x="213.36" y="109.22"/>
<pinref part="RN1" gate="G$1" pin="5"/>
<wire x1="210.82" y1="99.06" x2="213.36" y2="99.06" width="0.1524" layer="91"/>
<wire x1="213.36" y1="104.14" x2="213.36" y2="99.06" width="0.1524" layer="91"/>
<junction x="213.36" y="104.14"/>
</segment>
</net>
<net name="SCL1" class="0">
<segment>
<pinref part="RN1" gate="G$1" pin="4"/>
<wire x1="190.5" y1="99.06" x2="185.42" y2="99.06" width="0.1524" layer="91"/>
<label x="182.88" y="99.06" size="1.778" layer="95"/>
</segment>
<segment>
<wire x1="147.32" y1="111.76" x2="152.4" y2="111.76" width="0.1524" layer="91"/>
<pinref part="U1" gate="A" pin="SCL"/>
<label x="152.4" y="111.76" size="1.778" layer="95"/>
</segment>
<segment>
<wire x1="210.82" y1="144.78" x2="218.44" y2="144.78" width="0.1524" layer="91"/>
<label x="218.44" y="144.78" size="1.778" layer="95"/>
<pinref part="JP1" gate="A" pin="2"/>
</segment>
</net>
<net name="SDA1" class="0">
<segment>
<pinref part="RN1" gate="G$1" pin="3"/>
<wire x1="190.5" y1="104.14" x2="185.42" y2="104.14" width="0.1524" layer="91"/>
<label x="182.88" y="104.14" size="1.778" layer="95"/>
</segment>
<segment>
<wire x1="147.32" y1="109.22" x2="152.4" y2="109.22" width="0.1524" layer="91"/>
<pinref part="U1" gate="A" pin="SDA"/>
<label x="152.4" y="109.22" size="1.778" layer="95"/>
</segment>
<segment>
<wire x1="210.82" y1="147.32" x2="218.44" y2="147.32" width="0.1524" layer="91"/>
<label x="218.44" y="147.32" size="1.778" layer="95"/>
<pinref part="JP1" gate="A" pin="3"/>
</segment>
</net>
<net name="SCL2" class="0">
<segment>
<pinref part="RN1" gate="G$1" pin="2"/>
<wire x1="190.5" y1="109.22" x2="185.42" y2="109.22" width="0.1524" layer="91"/>
<label x="182.88" y="109.22" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U2" gate="A" pin="SCL"/>
<wire x1="276.86" y1="111.76" x2="281.94" y2="111.76" width="0.1524" layer="91"/>
<label x="281.94" y="111.76" size="1.778" layer="95"/>
</segment>
<segment>
<wire x1="210.82" y1="149.86" x2="218.44" y2="149.86" width="0.1524" layer="91"/>
<label x="218.44" y="149.86" size="1.778" layer="95"/>
<pinref part="JP1" gate="A" pin="4"/>
</segment>
</net>
<net name="SDA2" class="0">
<segment>
<pinref part="RN1" gate="G$1" pin="1"/>
<wire x1="190.5" y1="114.3" x2="185.42" y2="114.3" width="0.1524" layer="91"/>
<label x="182.88" y="114.3" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U2" gate="A" pin="SDA"/>
<wire x1="276.86" y1="109.22" x2="281.94" y2="109.22" width="0.1524" layer="91"/>
<label x="281.94" y="109.22" size="1.778" layer="95"/>
</segment>
<segment>
<wire x1="210.82" y1="152.4" x2="218.44" y2="152.4" width="0.1524" layer="91"/>
<label x="218.44" y="152.4" size="1.778" layer="95"/>
<pinref part="JP1" gate="A" pin="5"/>
</segment>
</net>
<net name="GND" class="0">
<segment>
<wire x1="111.76" y1="101.6" x2="106.68" y2="101.6" width="0.1524" layer="91"/>
<wire x1="106.68" y1="101.6" x2="106.68" y2="88.9" width="0.1524" layer="91"/>
<pinref part="U1" gate="A" pin="ADDR"/>
<pinref part="SUPPLY1" gate="GND" pin="GND"/>
</segment>
<segment>
<wire x1="147.32" y1="93.98" x2="152.4" y2="93.98" width="0.1524" layer="91"/>
<wire x1="152.4" y1="93.98" x2="152.4" y2="99.06" width="0.1524" layer="91"/>
<wire x1="152.4" y1="99.06" x2="152.4" y2="104.14" width="0.1524" layer="91"/>
<wire x1="152.4" y1="104.14" x2="147.32" y2="104.14" width="0.1524" layer="91"/>
<wire x1="147.32" y1="99.06" x2="152.4" y2="99.06" width="0.1524" layer="91"/>
<junction x="152.4" y="99.06"/>
<wire x1="152.4" y1="93.98" x2="152.4" y2="88.9" width="0.1524" layer="91"/>
<junction x="152.4" y="93.98"/>
<pinref part="U1" gate="A" pin="GND"/>
<pinref part="U1" gate="A" pin="DRDY_INT"/>
<pinref part="U1" gate="A" pin="PAD"/>
<pinref part="SUPPLY3" gate="GND" pin="GND"/>
<wire x1="152.4" y1="93.98" x2="162.56" y2="93.98" width="0.1524" layer="91"/>
<wire x1="162.56" y1="93.98" x2="162.56" y2="121.92" width="0.1524" layer="91"/>
<pinref part="C1" gate="G$1" pin="2"/>
<wire x1="162.56" y1="121.92" x2="119.38" y2="121.92" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="U2" gate="A" pin="GND"/>
<wire x1="276.86" y1="93.98" x2="281.94" y2="93.98" width="0.1524" layer="91"/>
<wire x1="281.94" y1="93.98" x2="281.94" y2="99.06" width="0.1524" layer="91"/>
<pinref part="U2" gate="A" pin="DRDY_INT"/>
<wire x1="281.94" y1="99.06" x2="281.94" y2="104.14" width="0.1524" layer="91"/>
<wire x1="281.94" y1="104.14" x2="276.86" y2="104.14" width="0.1524" layer="91"/>
<pinref part="U2" gate="A" pin="PAD"/>
<wire x1="276.86" y1="99.06" x2="281.94" y2="99.06" width="0.1524" layer="91"/>
<junction x="281.94" y="99.06"/>
<wire x1="281.94" y1="93.98" x2="281.94" y2="88.9" width="0.1524" layer="91"/>
<junction x="281.94" y="93.98"/>
<pinref part="SUPPLY5" gate="GND" pin="GND"/>
<wire x1="281.94" y1="93.98" x2="292.1" y2="93.98" width="0.1524" layer="91"/>
<wire x1="292.1" y1="93.98" x2="292.1" y2="121.92" width="0.1524" layer="91"/>
<pinref part="C2" gate="G$1" pin="2"/>
<wire x1="292.1" y1="121.92" x2="248.92" y2="121.92" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="U2" gate="A" pin="ADDR"/>
<wire x1="241.3" y1="101.6" x2="236.22" y2="101.6" width="0.1524" layer="91"/>
<wire x1="236.22" y1="101.6" x2="236.22" y2="88.9" width="0.1524" layer="91"/>
<pinref part="SUPPLY4" gate="GND" pin="GND"/>
</segment>
<segment>
<wire x1="210.82" y1="142.24" x2="218.44" y2="142.24" width="0.1524" layer="91"/>
<wire x1="218.44" y1="142.24" x2="218.44" y2="139.7" width="0.1524" layer="91"/>
<pinref part="SUPPLY2" gate="GND" pin="GND"/>
<pinref part="JP1" gate="A" pin="1"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
<errors>
<approved hash="104,1,111.76,101.6,U1,ADDR,GND,,,"/>
<approved hash="104,1,147.32,104.14,U1,DRDY_INT,GND,,,"/>
<approved hash="104,1,147.32,99.06,U1,PAD,GND,,,"/>
<approved hash="104,1,241.3,101.6,U2,ADDR,GND,,,"/>
<approved hash="104,1,276.86,104.14,U2,DRDY_INT,GND,,,"/>
<approved hash="104,1,276.86,99.06,U2,PAD,GND,,,"/>
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
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports the association of 3D packages
with devices in libraries, schematics, and board files. Those 3D
packages will not be understood (or retained) with this version.
</note>
</compatibility>
</eagle>
