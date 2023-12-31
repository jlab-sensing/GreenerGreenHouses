<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="9.6.2">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="yes" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
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
<library name="PassiveLiFiTag">
<packages>
<package name="RM_10_ADI">
<smd name="1" x="-2.1717" y="1" dx="1.524" dy="0.3302" layer="1"/>
<smd name="2" x="-2.1717" y="0.5" dx="1.524" dy="0.3302" layer="1"/>
<smd name="3" x="-2.1717" y="0" dx="1.524" dy="0.3302" layer="1"/>
<smd name="4" x="-2.1717" y="-0.5" dx="1.524" dy="0.3302" layer="1"/>
<smd name="5" x="-2.1717" y="-1" dx="1.524" dy="0.3302" layer="1"/>
<smd name="6" x="2.1717" y="-1" dx="1.524" dy="0.3302" layer="1"/>
<smd name="7" x="2.1717" y="-0.5" dx="1.524" dy="0.3302" layer="1"/>
<smd name="8" x="2.1717" y="0" dx="1.524" dy="0.3302" layer="1"/>
<smd name="9" x="2.1717" y="0.5" dx="1.524" dy="0.3302" layer="1"/>
<smd name="10" x="2.1717" y="1" dx="1.524" dy="0.3302" layer="1"/>
<wire x1="-1.5494" y1="0.8382" x2="-1.5494" y2="1.1684" width="0.1524" layer="51"/>
<wire x1="-1.5494" y1="1.1684" x2="-2.5908" y2="1.1684" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="1.1684" x2="-2.5908" y2="0.8382" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="0.8382" x2="-1.5494" y2="0.8382" width="0.1524" layer="51"/>
<wire x1="-1.5494" y1="0.3302" x2="-1.5494" y2="0.6604" width="0.1524" layer="51"/>
<wire x1="-1.5494" y1="0.6604" x2="-2.5908" y2="0.6604" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="0.6604" x2="-2.5908" y2="0.3302" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="0.3302" x2="-1.5494" y2="0.3302" width="0.1524" layer="51"/>
<wire x1="-1.5494" y1="-0.1524" x2="-1.5494" y2="0.1524" width="0.1524" layer="51"/>
<wire x1="-1.5494" y1="0.1524" x2="-2.5908" y2="0.1524" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="0.1524" x2="-2.5908" y2="-0.1778" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="-0.1778" x2="-1.5494" y2="-0.1524" width="0.1524" layer="51"/>
<wire x1="-1.5494" y1="-0.6604" x2="-1.5494" y2="-0.3302" width="0.1524" layer="51"/>
<wire x1="-1.5494" y1="-0.3302" x2="-2.5908" y2="-0.3302" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="-0.3302" x2="-2.5908" y2="-0.6604" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="-0.6604" x2="-1.5494" y2="-0.6604" width="0.1524" layer="51"/>
<wire x1="-1.5494" y1="-1.1684" x2="-1.5494" y2="-0.8382" width="0.1524" layer="51"/>
<wire x1="-1.5494" y1="-0.8382" x2="-2.5908" y2="-0.8382" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="-0.8382" x2="-2.5908" y2="-1.1684" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="-1.1684" x2="-1.5494" y2="-1.1684" width="0.1524" layer="51"/>
<wire x1="1.5494" y1="-0.8382" x2="1.5494" y2="-1.1684" width="0.1524" layer="51"/>
<wire x1="1.5494" y1="-1.1684" x2="2.5908" y2="-1.1684" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="-1.1684" x2="2.5908" y2="-0.8382" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="-0.8382" x2="1.5494" y2="-0.8382" width="0.1524" layer="51"/>
<wire x1="1.5494" y1="-0.3302" x2="1.5494" y2="-0.6604" width="0.1524" layer="51"/>
<wire x1="1.5494" y1="-0.6604" x2="2.5908" y2="-0.6604" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="-0.6604" x2="2.5908" y2="-0.3302" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="-0.3302" x2="1.5494" y2="-0.3302" width="0.1524" layer="51"/>
<wire x1="1.5494" y1="0.1524" x2="1.5494" y2="-0.1524" width="0.1524" layer="51"/>
<wire x1="1.5494" y1="-0.1524" x2="2.5908" y2="-0.1524" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="-0.1524" x2="2.5908" y2="0.1778" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="0.1778" x2="1.5494" y2="0.1524" width="0.1524" layer="51"/>
<wire x1="1.5494" y1="0.6604" x2="1.5494" y2="0.3302" width="0.1524" layer="51"/>
<wire x1="1.5494" y1="0.3302" x2="2.5908" y2="0.3302" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="0.3302" x2="2.5908" y2="0.6604" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="0.6604" x2="1.5494" y2="0.6604" width="0.1524" layer="51"/>
<wire x1="1.5494" y1="1.1684" x2="1.5494" y2="0.8382" width="0.1524" layer="51"/>
<wire x1="1.5494" y1="0.8382" x2="2.5908" y2="0.8382" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="0.8382" x2="2.5908" y2="1.1684" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="1.1684" x2="1.5494" y2="1.1684" width="0.1524" layer="51"/>
<wire x1="-1.5494" y1="-1.5494" x2="1.5494" y2="-1.5494" width="0.1524" layer="51"/>
<wire x1="1.5494" y1="-1.5494" x2="1.5494" y2="1.5494" width="0.1524" layer="51"/>
<wire x1="1.5494" y1="1.5494" x2="0.3048" y2="1.5494" width="0.1524" layer="51"/>
<wire x1="0.3048" y1="1.5494" x2="-0.3048" y2="1.5494" width="0.1524" layer="51"/>
<wire x1="-0.3048" y1="1.5494" x2="-1.5494" y2="1.5494" width="0.1524" layer="51"/>
<wire x1="-1.5494" y1="1.5494" x2="-1.5494" y2="-1.5494" width="0.1524" layer="51"/>
<wire x1="0.3048" y1="1.5494" x2="-0.3048" y2="1.5494" width="0.1524" layer="51" curve="-180"/>
<text x="-1.7526" y="0.2032" size="1.27" layer="51" ratio="6" rot="SR0">*</text>
<wire x1="-1.6764" y1="-1.6764" x2="1.6764" y2="-1.6764" width="0.1524" layer="21"/>
<wire x1="1.6764" y1="-1.6764" x2="1.6764" y2="-1.4986" width="0.1524" layer="21"/>
<wire x1="1.6764" y1="1.6764" x2="-1.6764" y2="1.6764" width="0.1524" layer="21"/>
<wire x1="-1.6764" y1="1.6764" x2="-1.6764" y2="1.4986" width="0.1524" layer="21"/>
<wire x1="-1.6764" y1="-1.4986" x2="-1.6764" y2="-1.6764" width="0.1524" layer="21"/>
<wire x1="1.6764" y1="1.4986" x2="1.6764" y2="1.6764" width="0.1524" layer="21"/>
<polygon width="0.0254" layer="21">
<vertex x="3.4417" y="1.1905"/>
<vertex x="3.4417" y="0.8095"/>
<vertex x="3.1877" y="0.8095"/>
<vertex x="3.1877" y="1.1905"/>
</polygon>
<text x="-2.9972" y="1.1938" size="1.27" layer="21" ratio="6" rot="SR0">*</text>
<wire x1="-1.5494" y1="0" x2="-1.5494" y2="3.4544" width="0.1524" layer="47"/>
<wire x1="-1.5494" y1="3.4544" x2="-1.5494" y2="3.8354" width="0.1524" layer="47"/>
<wire x1="1.5494" y1="0" x2="1.5494" y2="3.4544" width="0.1524" layer="47"/>
<wire x1="1.5494" y1="3.4544" x2="1.5494" y2="3.8354" width="0.1524" layer="47"/>
<wire x1="-1.5494" y1="3.4544" x2="-2.8194" y2="3.4544" width="0.1524" layer="47"/>
<wire x1="1.5494" y1="3.4544" x2="2.8194" y2="3.4544" width="0.1524" layer="47"/>
<wire x1="-1.5494" y1="3.4544" x2="-1.8034" y2="3.5814" width="0.1524" layer="47"/>
<wire x1="-1.5494" y1="3.4544" x2="-1.8034" y2="3.3274" width="0.1524" layer="47"/>
<wire x1="-1.8034" y1="3.5814" x2="-1.8034" y2="3.3274" width="0.1524" layer="47"/>
<wire x1="1.5494" y1="3.4544" x2="1.8034" y2="3.5814" width="0.1524" layer="47"/>
<wire x1="1.5494" y1="3.4544" x2="1.8034" y2="3.3274" width="0.1524" layer="47"/>
<wire x1="1.8034" y1="3.5814" x2="1.8034" y2="3.3274" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="-3.8354" x2="-2.5908" y2="-3.4544" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="-3.4544" x2="-2.5908" y2="5.3594" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="5.3594" x2="-2.5908" y2="5.7404" width="0.1524" layer="47"/>
<wire x1="2.5908" y1="0" x2="2.5908" y2="5.3594" width="0.1524" layer="47"/>
<wire x1="2.5908" y1="5.3594" x2="2.5908" y2="5.7404" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="5.3594" x2="2.5908" y2="5.3594" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="5.3594" x2="-2.3368" y2="5.4864" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="5.3594" x2="-2.3368" y2="5.2324" width="0.1524" layer="47"/>
<wire x1="-2.3368" y1="5.4864" x2="-2.3368" y2="5.2324" width="0.1524" layer="47"/>
<wire x1="2.5908" y1="5.3594" x2="2.3368" y2="5.4864" width="0.1524" layer="47"/>
<wire x1="2.5908" y1="5.3594" x2="2.3368" y2="5.2324" width="0.1524" layer="47"/>
<wire x1="2.3368" y1="5.4864" x2="2.3368" y2="5.2324" width="0.1524" layer="47"/>
<wire x1="0" y1="1.5494" x2="4.0894" y2="1.5494" width="0.1524" layer="47"/>
<wire x1="4.0894" y1="1.5494" x2="4.4704" y2="1.5494" width="0.1524" layer="47"/>
<wire x1="0" y1="-1.5494" x2="4.0894" y2="-1.5494" width="0.1524" layer="47"/>
<wire x1="4.0894" y1="-1.5494" x2="4.4704" y2="-1.5494" width="0.1524" layer="47"/>
<wire x1="4.0894" y1="1.5494" x2="4.0894" y2="2.8194" width="0.1524" layer="47"/>
<wire x1="4.0894" y1="-1.5494" x2="4.0894" y2="-2.8194" width="0.1524" layer="47"/>
<wire x1="4.0894" y1="1.5494" x2="3.9624" y2="1.8034" width="0.1524" layer="47"/>
<wire x1="4.0894" y1="1.5494" x2="4.2164" y2="1.8034" width="0.1524" layer="47"/>
<wire x1="3.9624" y1="1.8034" x2="4.2164" y2="1.8034" width="0.1524" layer="47"/>
<wire x1="4.0894" y1="-1.5494" x2="3.9624" y2="-1.8034" width="0.1524" layer="47"/>
<wire x1="4.0894" y1="-1.5494" x2="4.2164" y2="-1.8034" width="0.1524" layer="47"/>
<wire x1="3.9624" y1="-1.8034" x2="4.2164" y2="-1.8034" width="0.1524" layer="47"/>
<wire x1="-2.1844" y1="0.9906" x2="-4.7244" y2="0.9906" width="0.1524" layer="47"/>
<wire x1="-4.7244" y1="0.9906" x2="-5.08" y2="0.9906" width="0.1524" layer="47"/>
<wire x1="-2.1844" y1="0.508" x2="-4.7244" y2="0.508" width="0.1524" layer="47"/>
<wire x1="-4.7244" y1="0.508" x2="-5.08" y2="0.508" width="0.1524" layer="47"/>
<wire x1="-4.7244" y1="0.9906" x2="-4.7244" y2="2.2606" width="0.1524" layer="47"/>
<wire x1="-4.7244" y1="0.508" x2="-4.7244" y2="-0.762" width="0.1524" layer="47"/>
<wire x1="-4.7244" y1="0.9906" x2="-4.826" y2="1.2446" width="0.1524" layer="47"/>
<wire x1="-4.7244" y1="0.9906" x2="-4.572" y2="1.2446" width="0.1524" layer="47"/>
<wire x1="-4.826" y1="1.2446" x2="-4.572" y2="1.2446" width="0.1524" layer="47"/>
<wire x1="-4.7244" y1="0.508" x2="-4.826" y2="0.254" width="0.1524" layer="47"/>
<wire x1="-4.7244" y1="0.508" x2="-4.572" y2="0.254" width="0.1524" layer="47"/>
<wire x1="-4.826" y1="0.254" x2="-4.572" y2="0.254" width="0.1524" layer="47"/>
<wire x1="-1.778" y1="0" x2="-1.778" y2="-3.4544" width="0.1524" layer="47"/>
<wire x1="-1.778" y1="-3.4544" x2="-1.778" y2="-3.8354" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="-3.4544" x2="-3.8608" y2="-3.4544" width="0.1524" layer="47"/>
<wire x1="-1.778" y1="-3.4544" x2="-0.508" y2="-3.4544" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="-3.4544" x2="-2.8448" y2="-3.3274" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="-3.4544" x2="-2.8448" y2="-3.5814" width="0.1524" layer="47"/>
<wire x1="-2.8448" y1="-3.3274" x2="-2.8448" y2="-3.5814" width="0.1524" layer="47"/>
<wire x1="-1.778" y1="-3.4544" x2="-1.524" y2="-3.3274" width="0.1524" layer="47"/>
<wire x1="-1.778" y1="-3.4544" x2="-1.524" y2="-3.5814" width="0.1524" layer="47"/>
<wire x1="-1.524" y1="-3.3274" x2="-1.524" y2="-3.5814" width="0.1524" layer="47"/>
<text x="-15.2146" y="-6.6294" size="1.27" layer="47" ratio="6" rot="SR0">Default Padstyle: RX60Y13D0T</text>
<text x="-15.5702" y="-8.1534" size="1.27" layer="47" ratio="6" rot="SR0">Pin One Padstyle: RX60Y13D0T</text>
<text x="-14.8082" y="-12.7254" size="1.27" layer="47" ratio="6" rot="SR0">Alt 1 Padstyle: OX60Y90D30P</text>
<text x="-14.8082" y="-14.2494" size="1.27" layer="47" ratio="6" rot="SR0">Alt 2 Padstyle: OX90Y60D30P</text>
<text x="-4.0386" y="3.9624" size="0.635" layer="47" ratio="4" rot="SR0">0.122in/3.099mm</text>
<text x="-4.0386" y="5.8674" size="0.635" layer="47" ratio="4" rot="SR0">0.203in/5.156mm</text>
<text x="4.5974" y="-0.3048" size="0.635" layer="47" ratio="4" rot="SR0">0.122in/3.099mm</text>
<text x="-11.5824" y="0.4318" size="0.635" layer="47" ratio="4" rot="SR0">0.02in/0.5mm</text>
<text x="-6.223" y="-4.5974" size="0.635" layer="47" ratio="4" rot="SR0">0.032in/0.813mm</text>
<text x="-1.7272" y="-0.635" size="1.27" layer="27" ratio="6" rot="SR0">&gt;Value</text>
</package>
<package name="RM_10_ADI-M">
<smd name="1" x="-2.2225" y="1" dx="1.8288" dy="0.3302" layer="1"/>
<smd name="2" x="-2.2225" y="0.5" dx="1.8288" dy="0.3302" layer="1"/>
<smd name="3" x="-2.2225" y="0" dx="1.8288" dy="0.3302" layer="1"/>
<smd name="4" x="-2.2225" y="-0.5" dx="1.8288" dy="0.3302" layer="1"/>
<smd name="5" x="-2.2225" y="-1" dx="1.8288" dy="0.3302" layer="1"/>
<smd name="6" x="2.2225" y="-1" dx="1.8288" dy="0.3302" layer="1"/>
<smd name="7" x="2.2225" y="-0.5" dx="1.8288" dy="0.3302" layer="1"/>
<smd name="8" x="2.2225" y="0" dx="1.8288" dy="0.3302" layer="1"/>
<smd name="9" x="2.2225" y="0.5" dx="1.8288" dy="0.3302" layer="1"/>
<smd name="10" x="2.2225" y="1" dx="1.8288" dy="0.3302" layer="1"/>
<wire x1="-1.5494" y1="0.8382" x2="-1.5494" y2="1.1684" width="0.1524" layer="51"/>
<wire x1="-1.5494" y1="1.1684" x2="-2.5908" y2="1.1684" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="1.1684" x2="-2.5908" y2="0.8382" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="0.8382" x2="-1.5494" y2="0.8382" width="0.1524" layer="51"/>
<wire x1="-1.5494" y1="0.3302" x2="-1.5494" y2="0.6604" width="0.1524" layer="51"/>
<wire x1="-1.5494" y1="0.6604" x2="-2.5908" y2="0.6604" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="0.6604" x2="-2.5908" y2="0.3302" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="0.3302" x2="-1.5494" y2="0.3302" width="0.1524" layer="51"/>
<wire x1="-1.5494" y1="-0.1524" x2="-1.5494" y2="0.1524" width="0.1524" layer="51"/>
<wire x1="-1.5494" y1="0.1524" x2="-2.5908" y2="0.1524" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="0.1524" x2="-2.5908" y2="-0.1778" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="-0.1778" x2="-1.5494" y2="-0.1524" width="0.1524" layer="51"/>
<wire x1="-1.5494" y1="-0.6604" x2="-1.5494" y2="-0.3302" width="0.1524" layer="51"/>
<wire x1="-1.5494" y1="-0.3302" x2="-2.5908" y2="-0.3302" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="-0.3302" x2="-2.5908" y2="-0.6604" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="-0.6604" x2="-1.5494" y2="-0.6604" width="0.1524" layer="51"/>
<wire x1="-1.5494" y1="-1.1684" x2="-1.5494" y2="-0.8382" width="0.1524" layer="51"/>
<wire x1="-1.5494" y1="-0.8382" x2="-2.5908" y2="-0.8382" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="-0.8382" x2="-2.5908" y2="-1.1684" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="-1.1684" x2="-1.5494" y2="-1.1684" width="0.1524" layer="51"/>
<wire x1="1.5494" y1="-0.8382" x2="1.5494" y2="-1.1684" width="0.1524" layer="51"/>
<wire x1="1.5494" y1="-1.1684" x2="2.5908" y2="-1.1684" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="-1.1684" x2="2.5908" y2="-0.8382" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="-0.8382" x2="1.5494" y2="-0.8382" width="0.1524" layer="51"/>
<wire x1="1.5494" y1="-0.3302" x2="1.5494" y2="-0.6604" width="0.1524" layer="51"/>
<wire x1="1.5494" y1="-0.6604" x2="2.5908" y2="-0.6604" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="-0.6604" x2="2.5908" y2="-0.3302" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="-0.3302" x2="1.5494" y2="-0.3302" width="0.1524" layer="51"/>
<wire x1="1.5494" y1="0.1524" x2="1.5494" y2="-0.1524" width="0.1524" layer="51"/>
<wire x1="1.5494" y1="-0.1524" x2="2.5908" y2="-0.1524" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="-0.1524" x2="2.5908" y2="0.1778" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="0.1778" x2="1.5494" y2="0.1524" width="0.1524" layer="51"/>
<wire x1="1.5494" y1="0.6604" x2="1.5494" y2="0.3302" width="0.1524" layer="51"/>
<wire x1="1.5494" y1="0.3302" x2="2.5908" y2="0.3302" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="0.3302" x2="2.5908" y2="0.6604" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="0.6604" x2="1.5494" y2="0.6604" width="0.1524" layer="51"/>
<wire x1="1.5494" y1="1.1684" x2="1.5494" y2="0.8382" width="0.1524" layer="51"/>
<wire x1="1.5494" y1="0.8382" x2="2.5908" y2="0.8382" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="0.8382" x2="2.5908" y2="1.1684" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="1.1684" x2="1.5494" y2="1.1684" width="0.1524" layer="51"/>
<wire x1="-1.5494" y1="-1.5494" x2="1.5494" y2="-1.5494" width="0.1524" layer="51"/>
<wire x1="1.5494" y1="-1.5494" x2="1.5494" y2="1.5494" width="0.1524" layer="51"/>
<wire x1="1.5494" y1="1.5494" x2="0.3048" y2="1.5494" width="0.1524" layer="51"/>
<wire x1="0.3048" y1="1.5494" x2="-0.3048" y2="1.5494" width="0.1524" layer="51"/>
<wire x1="-0.3048" y1="1.5494" x2="-1.5494" y2="1.5494" width="0.1524" layer="51"/>
<wire x1="-1.5494" y1="1.5494" x2="-1.5494" y2="-1.5494" width="0.1524" layer="51"/>
<wire x1="0.3048" y1="1.5494" x2="-0.3048" y2="1.5494" width="0.1524" layer="51" curve="-180"/>
<text x="-1.7526" y="0.2032" size="1.27" layer="51" ratio="6" rot="SR0">*</text>
<wire x1="-1.6764" y1="-1.6764" x2="1.6764" y2="-1.6764" width="0.1524" layer="21"/>
<wire x1="1.6764" y1="1.6764" x2="-1.6764" y2="1.6764" width="0.1524" layer="21"/>
<polygon width="0.0254" layer="21">
<vertex x="3.6449" y="1.1905"/>
<vertex x="3.6449" y="0.8095"/>
<vertex x="3.3909" y="0.8095"/>
<vertex x="3.3909" y="1.1905"/>
</polygon>
<text x="-3.048" y="1.1938" size="1.27" layer="21" ratio="6" rot="SR0">*</text>
<wire x1="-1.5494" y1="0" x2="-1.5494" y2="3.4544" width="0.1524" layer="47"/>
<wire x1="-1.5494" y1="3.4544" x2="-1.5494" y2="3.8354" width="0.1524" layer="47"/>
<wire x1="1.5494" y1="0" x2="1.5494" y2="3.4544" width="0.1524" layer="47"/>
<wire x1="1.5494" y1="3.4544" x2="1.5494" y2="3.8354" width="0.1524" layer="47"/>
<wire x1="-1.5494" y1="3.4544" x2="-2.8194" y2="3.4544" width="0.1524" layer="47"/>
<wire x1="1.5494" y1="3.4544" x2="2.8194" y2="3.4544" width="0.1524" layer="47"/>
<wire x1="-1.5494" y1="3.4544" x2="-1.8034" y2="3.5814" width="0.1524" layer="47"/>
<wire x1="-1.5494" y1="3.4544" x2="-1.8034" y2="3.3274" width="0.1524" layer="47"/>
<wire x1="-1.8034" y1="3.5814" x2="-1.8034" y2="3.3274" width="0.1524" layer="47"/>
<wire x1="1.5494" y1="3.4544" x2="1.8034" y2="3.5814" width="0.1524" layer="47"/>
<wire x1="1.5494" y1="3.4544" x2="1.8034" y2="3.3274" width="0.1524" layer="47"/>
<wire x1="1.8034" y1="3.5814" x2="1.8034" y2="3.3274" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="-3.8354" x2="-2.5908" y2="-3.4544" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="-3.4544" x2="-2.5908" y2="5.3594" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="5.3594" x2="-2.5908" y2="5.7404" width="0.1524" layer="47"/>
<wire x1="2.5908" y1="0" x2="2.5908" y2="5.3594" width="0.1524" layer="47"/>
<wire x1="2.5908" y1="5.3594" x2="2.5908" y2="5.7404" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="5.3594" x2="2.5908" y2="5.3594" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="5.3594" x2="-2.3368" y2="5.4864" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="5.3594" x2="-2.3368" y2="5.2324" width="0.1524" layer="47"/>
<wire x1="-2.3368" y1="5.4864" x2="-2.3368" y2="5.2324" width="0.1524" layer="47"/>
<wire x1="2.5908" y1="5.3594" x2="2.3368" y2="5.4864" width="0.1524" layer="47"/>
<wire x1="2.5908" y1="5.3594" x2="2.3368" y2="5.2324" width="0.1524" layer="47"/>
<wire x1="2.3368" y1="5.4864" x2="2.3368" y2="5.2324" width="0.1524" layer="47"/>
<wire x1="0" y1="1.5494" x2="4.0894" y2="1.5494" width="0.1524" layer="47"/>
<wire x1="4.0894" y1="1.5494" x2="4.4704" y2="1.5494" width="0.1524" layer="47"/>
<wire x1="0" y1="-1.5494" x2="4.0894" y2="-1.5494" width="0.1524" layer="47"/>
<wire x1="4.0894" y1="-1.5494" x2="4.4704" y2="-1.5494" width="0.1524" layer="47"/>
<wire x1="4.0894" y1="1.5494" x2="4.0894" y2="2.8194" width="0.1524" layer="47"/>
<wire x1="4.0894" y1="-1.5494" x2="4.0894" y2="-2.8194" width="0.1524" layer="47"/>
<wire x1="4.0894" y1="1.5494" x2="3.9624" y2="1.8034" width="0.1524" layer="47"/>
<wire x1="4.0894" y1="1.5494" x2="4.2164" y2="1.8034" width="0.1524" layer="47"/>
<wire x1="3.9624" y1="1.8034" x2="4.2164" y2="1.8034" width="0.1524" layer="47"/>
<wire x1="4.0894" y1="-1.5494" x2="3.9624" y2="-1.8034" width="0.1524" layer="47"/>
<wire x1="4.0894" y1="-1.5494" x2="4.2164" y2="-1.8034" width="0.1524" layer="47"/>
<wire x1="3.9624" y1="-1.8034" x2="4.2164" y2="-1.8034" width="0.1524" layer="47"/>
<wire x1="-2.2352" y1="0.9906" x2="-4.7752" y2="0.9906" width="0.1524" layer="47"/>
<wire x1="-4.7752" y1="0.9906" x2="-5.1308" y2="0.9906" width="0.1524" layer="47"/>
<wire x1="-2.2352" y1="0.508" x2="-4.7752" y2="0.508" width="0.1524" layer="47"/>
<wire x1="-4.7752" y1="0.508" x2="-5.1308" y2="0.508" width="0.1524" layer="47"/>
<wire x1="-4.7752" y1="0.9906" x2="-4.7752" y2="2.2606" width="0.1524" layer="47"/>
<wire x1="-4.7752" y1="0.508" x2="-4.7752" y2="-0.762" width="0.1524" layer="47"/>
<wire x1="-4.7752" y1="0.9906" x2="-4.8768" y2="1.2446" width="0.1524" layer="47"/>
<wire x1="-4.7752" y1="0.9906" x2="-4.6228" y2="1.2446" width="0.1524" layer="47"/>
<wire x1="-4.8768" y1="1.2446" x2="-4.6228" y2="1.2446" width="0.1524" layer="47"/>
<wire x1="-4.7752" y1="0.508" x2="-4.8768" y2="0.254" width="0.1524" layer="47"/>
<wire x1="-4.7752" y1="0.508" x2="-4.6228" y2="0.254" width="0.1524" layer="47"/>
<wire x1="-4.8768" y1="0.254" x2="-4.6228" y2="0.254" width="0.1524" layer="47"/>
<wire x1="-1.778" y1="0" x2="-1.778" y2="-3.4544" width="0.1524" layer="47"/>
<wire x1="-1.778" y1="-3.4544" x2="-1.778" y2="-3.8354" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="-3.4544" x2="-3.8608" y2="-3.4544" width="0.1524" layer="47"/>
<wire x1="-1.778" y1="-3.4544" x2="-0.508" y2="-3.4544" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="-3.4544" x2="-2.8448" y2="-3.3274" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="-3.4544" x2="-2.8448" y2="-3.5814" width="0.1524" layer="47"/>
<wire x1="-2.8448" y1="-3.3274" x2="-2.8448" y2="-3.5814" width="0.1524" layer="47"/>
<wire x1="-1.778" y1="-3.4544" x2="-1.524" y2="-3.3274" width="0.1524" layer="47"/>
<wire x1="-1.778" y1="-3.4544" x2="-1.524" y2="-3.5814" width="0.1524" layer="47"/>
<wire x1="-1.524" y1="-3.3274" x2="-1.524" y2="-3.5814" width="0.1524" layer="47"/>
<text x="-15.2146" y="-6.6294" size="1.27" layer="47" ratio="6" rot="SR0">Default Padstyle: RX72Y13D0T</text>
<text x="-15.5702" y="-8.1534" size="1.27" layer="47" ratio="6" rot="SR0">Pin One Padstyle: RX72Y13D0T</text>
<text x="-14.8082" y="-12.7254" size="1.27" layer="47" ratio="6" rot="SR0">Alt 1 Padstyle: OX60Y90D30P</text>
<text x="-14.8082" y="-14.2494" size="1.27" layer="47" ratio="6" rot="SR0">Alt 2 Padstyle: OX90Y60D30P</text>
<text x="-4.0386" y="3.9624" size="0.635" layer="47" ratio="4" rot="SR0">0.122in/3.099mm</text>
<text x="-4.0386" y="5.8674" size="0.635" layer="47" ratio="4" rot="SR0">0.203in/5.156mm</text>
<text x="4.5974" y="-0.3048" size="0.635" layer="47" ratio="4" rot="SR0">0.122in/3.099mm</text>
<text x="-11.6332" y="0.4318" size="0.635" layer="47" ratio="4" rot="SR0">0.02in/0.5mm</text>
<text x="-6.223" y="-4.5974" size="0.635" layer="47" ratio="4" rot="SR0">0.032in/0.813mm</text>
<text x="-3.2766" y="-0.635" size="1.27" layer="27" ratio="6" rot="SR0">&gt;Name</text>
<text x="-1.7272" y="-0.635" size="1.27" layer="27" ratio="6" rot="SR0">&gt;Value</text>
<text x="-3.2766" y="-0.635" size="1.27" layer="27" ratio="6" rot="SR0">&gt;Name</text>
</package>
<package name="RM_10_ADI-L">
<smd name="1" x="-2.1209" y="1" dx="1.2192" dy="0.2794" layer="1"/>
<smd name="2" x="-2.1209" y="0.5" dx="1.2192" dy="0.2794" layer="1"/>
<smd name="3" x="-2.1209" y="0" dx="1.2192" dy="0.2794" layer="1"/>
<smd name="4" x="-2.1209" y="-0.5" dx="1.2192" dy="0.2794" layer="1"/>
<smd name="5" x="-2.1209" y="-1" dx="1.2192" dy="0.2794" layer="1"/>
<smd name="6" x="2.1209" y="-1" dx="1.2192" dy="0.2794" layer="1"/>
<smd name="7" x="2.1209" y="-0.5" dx="1.2192" dy="0.2794" layer="1"/>
<smd name="8" x="2.1209" y="0" dx="1.2192" dy="0.2794" layer="1"/>
<smd name="9" x="2.1209" y="0.5" dx="1.2192" dy="0.2794" layer="1"/>
<smd name="10" x="2.1209" y="1" dx="1.2192" dy="0.2794" layer="1"/>
<wire x1="-1.5494" y1="0.8382" x2="-1.5494" y2="1.1684" width="0.1524" layer="51"/>
<wire x1="-1.5494" y1="1.1684" x2="-2.5908" y2="1.1684" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="1.1684" x2="-2.5908" y2="0.8382" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="0.8382" x2="-1.5494" y2="0.8382" width="0.1524" layer="51"/>
<wire x1="-1.5494" y1="0.3302" x2="-1.5494" y2="0.6604" width="0.1524" layer="51"/>
<wire x1="-1.5494" y1="0.6604" x2="-2.5908" y2="0.6604" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="0.6604" x2="-2.5908" y2="0.3302" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="0.3302" x2="-1.5494" y2="0.3302" width="0.1524" layer="51"/>
<wire x1="-1.5494" y1="-0.1524" x2="-1.5494" y2="0.1524" width="0.1524" layer="51"/>
<wire x1="-1.5494" y1="0.1524" x2="-2.5908" y2="0.1524" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="0.1524" x2="-2.5908" y2="-0.1778" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="-0.1778" x2="-1.5494" y2="-0.1524" width="0.1524" layer="51"/>
<wire x1="-1.5494" y1="-0.6604" x2="-1.5494" y2="-0.3302" width="0.1524" layer="51"/>
<wire x1="-1.5494" y1="-0.3302" x2="-2.5908" y2="-0.3302" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="-0.3302" x2="-2.5908" y2="-0.6604" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="-0.6604" x2="-1.5494" y2="-0.6604" width="0.1524" layer="51"/>
<wire x1="-1.5494" y1="-1.1684" x2="-1.5494" y2="-0.8382" width="0.1524" layer="51"/>
<wire x1="-1.5494" y1="-0.8382" x2="-2.5908" y2="-0.8382" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="-0.8382" x2="-2.5908" y2="-1.1684" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="-1.1684" x2="-1.5494" y2="-1.1684" width="0.1524" layer="51"/>
<wire x1="1.5494" y1="-0.8382" x2="1.5494" y2="-1.1684" width="0.1524" layer="51"/>
<wire x1="1.5494" y1="-1.1684" x2="2.5908" y2="-1.1684" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="-1.1684" x2="2.5908" y2="-0.8382" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="-0.8382" x2="1.5494" y2="-0.8382" width="0.1524" layer="51"/>
<wire x1="1.5494" y1="-0.3302" x2="1.5494" y2="-0.6604" width="0.1524" layer="51"/>
<wire x1="1.5494" y1="-0.6604" x2="2.5908" y2="-0.6604" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="-0.6604" x2="2.5908" y2="-0.3302" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="-0.3302" x2="1.5494" y2="-0.3302" width="0.1524" layer="51"/>
<wire x1="1.5494" y1="0.1524" x2="1.5494" y2="-0.1524" width="0.1524" layer="51"/>
<wire x1="1.5494" y1="-0.1524" x2="2.5908" y2="-0.1524" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="-0.1524" x2="2.5908" y2="0.1778" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="0.1778" x2="1.5494" y2="0.1524" width="0.1524" layer="51"/>
<wire x1="1.5494" y1="0.6604" x2="1.5494" y2="0.3302" width="0.1524" layer="51"/>
<wire x1="1.5494" y1="0.3302" x2="2.5908" y2="0.3302" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="0.3302" x2="2.5908" y2="0.6604" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="0.6604" x2="1.5494" y2="0.6604" width="0.1524" layer="51"/>
<wire x1="1.5494" y1="1.1684" x2="1.5494" y2="0.8382" width="0.1524" layer="51"/>
<wire x1="1.5494" y1="0.8382" x2="2.5908" y2="0.8382" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="0.8382" x2="2.5908" y2="1.1684" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="1.1684" x2="1.5494" y2="1.1684" width="0.1524" layer="51"/>
<wire x1="-1.5494" y1="-1.5494" x2="1.5494" y2="-1.5494" width="0.1524" layer="51"/>
<wire x1="1.5494" y1="-1.5494" x2="1.5494" y2="1.5494" width="0.1524" layer="51"/>
<wire x1="1.5494" y1="1.5494" x2="0.3048" y2="1.5494" width="0.1524" layer="51"/>
<wire x1="0.3048" y1="1.5494" x2="-0.3048" y2="1.5494" width="0.1524" layer="51"/>
<wire x1="-0.3048" y1="1.5494" x2="-1.5494" y2="1.5494" width="0.1524" layer="51"/>
<wire x1="-1.5494" y1="1.5494" x2="-1.5494" y2="-1.5494" width="0.1524" layer="51"/>
<wire x1="0.3048" y1="1.5494" x2="-0.3048" y2="1.5494" width="0.1524" layer="51" curve="-180"/>
<text x="-1.7526" y="0.2032" size="1.27" layer="51" ratio="6" rot="SR0">*</text>
<wire x1="-1.6764" y1="-1.6764" x2="1.6764" y2="-1.6764" width="0.1524" layer="21"/>
<wire x1="1.6764" y1="1.6764" x2="-1.6764" y2="1.6764" width="0.1524" layer="21"/>
<polygon width="0.0254" layer="21">
<vertex x="3.2385" y="1.1905"/>
<vertex x="3.2385" y="0.8095"/>
<vertex x="2.9845" y="0.8095"/>
<vertex x="2.9845" y="1.1905"/>
</polygon>
<text x="-2.9464" y="1.143" size="1.27" layer="21" ratio="6" rot="SR0">*</text>
<wire x1="-1.5494" y1="0" x2="-1.5494" y2="3.4544" width="0.1524" layer="47"/>
<wire x1="-1.5494" y1="3.4544" x2="-1.5494" y2="3.8354" width="0.1524" layer="47"/>
<wire x1="1.5494" y1="0" x2="1.5494" y2="3.4544" width="0.1524" layer="47"/>
<wire x1="1.5494" y1="3.4544" x2="1.5494" y2="3.8354" width="0.1524" layer="47"/>
<wire x1="-1.5494" y1="3.4544" x2="-2.8194" y2="3.4544" width="0.1524" layer="47"/>
<wire x1="1.5494" y1="3.4544" x2="2.8194" y2="3.4544" width="0.1524" layer="47"/>
<wire x1="-1.5494" y1="3.4544" x2="-1.8034" y2="3.5814" width="0.1524" layer="47"/>
<wire x1="-1.5494" y1="3.4544" x2="-1.8034" y2="3.3274" width="0.1524" layer="47"/>
<wire x1="-1.8034" y1="3.5814" x2="-1.8034" y2="3.3274" width="0.1524" layer="47"/>
<wire x1="1.5494" y1="3.4544" x2="1.8034" y2="3.5814" width="0.1524" layer="47"/>
<wire x1="1.5494" y1="3.4544" x2="1.8034" y2="3.3274" width="0.1524" layer="47"/>
<wire x1="1.8034" y1="3.5814" x2="1.8034" y2="3.3274" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="-3.8354" x2="-2.5908" y2="-3.4544" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="-3.4544" x2="-2.5908" y2="5.3594" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="5.3594" x2="-2.5908" y2="5.7404" width="0.1524" layer="47"/>
<wire x1="2.5908" y1="0" x2="2.5908" y2="5.3594" width="0.1524" layer="47"/>
<wire x1="2.5908" y1="5.3594" x2="2.5908" y2="5.7404" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="5.3594" x2="2.5908" y2="5.3594" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="5.3594" x2="-2.3368" y2="5.4864" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="5.3594" x2="-2.3368" y2="5.2324" width="0.1524" layer="47"/>
<wire x1="-2.3368" y1="5.4864" x2="-2.3368" y2="5.2324" width="0.1524" layer="47"/>
<wire x1="2.5908" y1="5.3594" x2="2.3368" y2="5.4864" width="0.1524" layer="47"/>
<wire x1="2.5908" y1="5.3594" x2="2.3368" y2="5.2324" width="0.1524" layer="47"/>
<wire x1="2.3368" y1="5.4864" x2="2.3368" y2="5.2324" width="0.1524" layer="47"/>
<wire x1="0" y1="1.5494" x2="4.0894" y2="1.5494" width="0.1524" layer="47"/>
<wire x1="4.0894" y1="1.5494" x2="4.4704" y2="1.5494" width="0.1524" layer="47"/>
<wire x1="0" y1="-1.5494" x2="4.0894" y2="-1.5494" width="0.1524" layer="47"/>
<wire x1="4.0894" y1="-1.5494" x2="4.4704" y2="-1.5494" width="0.1524" layer="47"/>
<wire x1="4.0894" y1="1.5494" x2="4.0894" y2="2.8194" width="0.1524" layer="47"/>
<wire x1="4.0894" y1="-1.5494" x2="4.0894" y2="-2.8194" width="0.1524" layer="47"/>
<wire x1="4.0894" y1="1.5494" x2="3.9624" y2="1.8034" width="0.1524" layer="47"/>
<wire x1="4.0894" y1="1.5494" x2="4.2164" y2="1.8034" width="0.1524" layer="47"/>
<wire x1="3.9624" y1="1.8034" x2="4.2164" y2="1.8034" width="0.1524" layer="47"/>
<wire x1="4.0894" y1="-1.5494" x2="3.9624" y2="-1.8034" width="0.1524" layer="47"/>
<wire x1="4.0894" y1="-1.5494" x2="4.2164" y2="-1.8034" width="0.1524" layer="47"/>
<wire x1="3.9624" y1="-1.8034" x2="4.2164" y2="-1.8034" width="0.1524" layer="47"/>
<wire x1="-2.1336" y1="0.9906" x2="-4.6736" y2="0.9906" width="0.1524" layer="47"/>
<wire x1="-4.6736" y1="0.9906" x2="-5.0292" y2="0.9906" width="0.1524" layer="47"/>
<wire x1="-2.1336" y1="0.508" x2="-4.6736" y2="0.508" width="0.1524" layer="47"/>
<wire x1="-4.6736" y1="0.508" x2="-5.0292" y2="0.508" width="0.1524" layer="47"/>
<wire x1="-4.6736" y1="0.9906" x2="-4.6736" y2="2.2606" width="0.1524" layer="47"/>
<wire x1="-4.6736" y1="0.508" x2="-4.6736" y2="-0.762" width="0.1524" layer="47"/>
<wire x1="-4.6736" y1="0.9906" x2="-4.7752" y2="1.2446" width="0.1524" layer="47"/>
<wire x1="-4.6736" y1="0.9906" x2="-4.5212" y2="1.2446" width="0.1524" layer="47"/>
<wire x1="-4.7752" y1="1.2446" x2="-4.5212" y2="1.2446" width="0.1524" layer="47"/>
<wire x1="-4.6736" y1="0.508" x2="-4.7752" y2="0.254" width="0.1524" layer="47"/>
<wire x1="-4.6736" y1="0.508" x2="-4.5212" y2="0.254" width="0.1524" layer="47"/>
<wire x1="-4.7752" y1="0.254" x2="-4.5212" y2="0.254" width="0.1524" layer="47"/>
<wire x1="-1.778" y1="0" x2="-1.778" y2="-3.4544" width="0.1524" layer="47"/>
<wire x1="-1.778" y1="-3.4544" x2="-1.778" y2="-3.8354" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="-3.4544" x2="-3.8608" y2="-3.4544" width="0.1524" layer="47"/>
<wire x1="-1.778" y1="-3.4544" x2="-0.508" y2="-3.4544" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="-3.4544" x2="-2.8448" y2="-3.3274" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="-3.4544" x2="-2.8448" y2="-3.5814" width="0.1524" layer="47"/>
<wire x1="-2.8448" y1="-3.3274" x2="-2.8448" y2="-3.5814" width="0.1524" layer="47"/>
<wire x1="-1.778" y1="-3.4544" x2="-1.524" y2="-3.3274" width="0.1524" layer="47"/>
<wire x1="-1.778" y1="-3.4544" x2="-1.524" y2="-3.5814" width="0.1524" layer="47"/>
<wire x1="-1.524" y1="-3.3274" x2="-1.524" y2="-3.5814" width="0.1524" layer="47"/>
<text x="-15.2146" y="-6.6294" size="1.27" layer="47" ratio="6" rot="SR0">Default Padstyle: RX48Y11D0T</text>
<text x="-15.5702" y="-8.1534" size="1.27" layer="47" ratio="6" rot="SR0">Pin One Padstyle: RX48Y11D0T</text>
<text x="-14.8082" y="-12.7254" size="1.27" layer="47" ratio="6" rot="SR0">Alt 1 Padstyle: OX60Y90D30P</text>
<text x="-14.8082" y="-14.2494" size="1.27" layer="47" ratio="6" rot="SR0">Alt 2 Padstyle: OX90Y60D30P</text>
<text x="-4.0386" y="3.9624" size="0.635" layer="47" ratio="4" rot="SR0">0.122in/3.099mm</text>
<text x="-4.0386" y="5.8674" size="0.635" layer="47" ratio="4" rot="SR0">0.203in/5.156mm</text>
<text x="4.5974" y="-0.3048" size="0.635" layer="47" ratio="4" rot="SR0">0.122in/3.099mm</text>
<text x="-11.5316" y="0.4318" size="0.635" layer="47" ratio="4" rot="SR0">0.02in/0.5mm</text>
<text x="-6.223" y="-4.5974" size="0.635" layer="47" ratio="4" rot="SR0">0.032in/0.813mm</text>
<text x="-1.7272" y="-0.635" size="1.27" layer="27" ratio="6" rot="SR0">&gt;Value</text>
<text x="-3.2766" y="-0.635" size="1.27" layer="27" ratio="6" rot="SR0">&gt;Name</text>
</package>
<package name="RM_8_ADI">
<smd name="1" x="-2.1717" y="0.975" dx="1.524" dy="0.4318" layer="1"/>
<smd name="2" x="-2.1717" y="0.325" dx="1.524" dy="0.4318" layer="1"/>
<smd name="3" x="-2.1717" y="-0.325" dx="1.524" dy="0.4318" layer="1"/>
<smd name="4" x="-2.1717" y="-0.975" dx="1.524" dy="0.4318" layer="1"/>
<smd name="5" x="2.1717" y="-0.975" dx="1.524" dy="0.4318" layer="1"/>
<smd name="6" x="2.1717" y="-0.325" dx="1.524" dy="0.4318" layer="1"/>
<smd name="7" x="2.1717" y="0.325" dx="1.524" dy="0.4318" layer="1"/>
<smd name="8" x="2.1717" y="0.975" dx="1.524" dy="0.4318" layer="1"/>
<wire x1="1.6002" y1="-1.6002" x2="1.6002" y2="-1.1684" width="0.1524" layer="51"/>
<wire x1="1.6002" y1="-0.7874" x2="1.6002" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="1.6002" y1="-0.127" x2="1.6002" y2="0.127" width="0.1524" layer="51"/>
<wire x1="1.6002" y1="0.508" x2="1.6002" y2="0.7874" width="0.1524" layer="51"/>
<wire x1="1.6002" y1="1.1684" x2="1.6002" y2="1.6002" width="0.1524" layer="51"/>
<wire x1="1.6002" y1="1.6002" x2="0.3048" y2="1.6002" width="0.1524" layer="51"/>
<wire x1="-0.3048" y1="1.6002" x2="-1.6002" y2="1.6002" width="0.1524" layer="51"/>
<wire x1="-1.6002" y1="1.6002" x2="-1.6002" y2="1.1684" width="0.1524" layer="51"/>
<wire x1="-1.6002" y1="0.7874" x2="-1.6002" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-1.6002" y1="0.127" x2="-1.6002" y2="-0.127" width="0.1524" layer="51"/>
<wire x1="-1.6002" y1="-0.508" x2="-1.6002" y2="-0.7874" width="0.1524" layer="51"/>
<wire x1="-1.6002" y1="-1.1684" x2="-1.6002" y2="-1.6002" width="0.1524" layer="51"/>
<wire x1="0.3048" y1="1.6002" x2="-0.3048" y2="1.6002" width="0.1524" layer="51" curve="-180"/>
<text x="-1.8034" y="0.254" size="1.27" layer="51" ratio="6" rot="SR0">*</text>
<wire x1="-1.6002" y1="0" x2="-1.6002" y2="3.5052" width="0.1524" layer="47"/>
<wire x1="1.6002" y1="0" x2="1.6002" y2="3.5052" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="5.4102" x2="-2.5908" y2="5.7912" width="0.1524" layer="47"/>
<wire x1="2.5908" y1="0" x2="2.5908" y2="5.4102" width="0.1524" layer="47"/>
<wire x1="0" y1="1.6002" x2="4.1402" y2="1.6002" width="0.1524" layer="47"/>
<wire x1="0" y1="-1.6002" x2="4.1402" y2="-1.6002" width="0.1524" layer="47"/>
<wire x1="-2.1844" y1="0.9652" x2="-4.7244" y2="0.9652" width="0.1524" layer="47"/>
<wire x1="-2.1844" y1="0.3302" x2="-4.7244" y2="0.3302" width="0.1524" layer="47"/>
<wire x1="-1.778" y1="0" x2="-1.778" y2="-3.5052" width="0.1524" layer="47"/>
<text x="-15.2146" y="-6.6802" size="1.27" layer="47" ratio="6" rot="SR0">Default Padstyle: RX60Y17D0T</text>
<text x="-15.5702" y="-8.2042" size="1.27" layer="47" ratio="6" rot="SR0">Pin One Padstyle: RX60Y17D0T</text>
<text x="-14.8082" y="-12.7762" size="1.27" layer="47" ratio="6" rot="SR0">Alt 1 Padstyle: OX60Y90D30P</text>
<text x="-14.8082" y="-14.3002" size="1.27" layer="47" ratio="6" rot="SR0">Alt 2 Padstyle: OX90Y60D30P</text>
<text x="-3.4544" y="4.0132" size="0.635" layer="47" ratio="4" rot="SR0">0.126in/3.2mm</text>
<text x="-4.0386" y="5.9182" size="0.635" layer="47" ratio="4" rot="SR0">0.203in/5.156mm</text>
<text x="4.6482" y="-0.3048" size="0.635" layer="47" ratio="4" rot="SR0">0.126in/3.2mm</text>
<text x="-12.7254" y="0.3302" size="0.635" layer="47" ratio="4" rot="SR0">0.026in/0.65mm</text>
<text x="-6.223" y="-4.6482" size="0.635" layer="47" ratio="4" rot="SR0">0.032in/0.813mm</text>
<text x="-2.9972" y="1.27" size="1.27" layer="21" ratio="6" rot="SR0">*</text>
<text x="-3.2766" y="-0.635" size="1.27" layer="27" ratio="6" rot="SR0">&gt;Name</text>
<text x="-1.7272" y="-0.635" size="1.27" layer="27" ratio="6" rot="SR0">&gt;Value</text>
<wire x1="-1.6002" y1="0.7874" x2="-1.6002" y2="1.1684" width="0.1524" layer="51"/>
<wire x1="-1.6002" y1="1.1684" x2="-2.5908" y2="1.1684" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="1.1684" x2="-2.5908" y2="0.7874" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="0.7874" x2="-1.6002" y2="0.7874" width="0.1524" layer="51"/>
<wire x1="-1.6002" y1="0.127" x2="-1.6002" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-1.6002" y1="0.508" x2="-2.5908" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="0.508" x2="-2.5908" y2="0.127" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="0.127" x2="-1.6002" y2="0.127" width="0.1524" layer="51"/>
<wire x1="-1.6002" y1="-0.508" x2="-1.6002" y2="-0.127" width="0.1524" layer="51"/>
<wire x1="-1.6002" y1="-0.127" x2="-2.5908" y2="-0.127" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="-0.127" x2="-2.5908" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="-0.508" x2="-1.6002" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-1.6002" y1="-1.1684" x2="-1.6002" y2="-0.7874" width="0.1524" layer="51"/>
<wire x1="-1.6002" y1="-0.7874" x2="-2.5908" y2="-0.7874" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="-0.7874" x2="-2.5908" y2="-1.1684" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="-1.1684" x2="-1.6002" y2="-1.1684" width="0.1524" layer="51"/>
<wire x1="1.6002" y1="-0.7874" x2="1.6002" y2="-1.1684" width="0.1524" layer="51"/>
<wire x1="1.6002" y1="-1.1684" x2="2.5908" y2="-1.1684" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="-1.1684" x2="2.5908" y2="-0.7874" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="-0.7874" x2="1.6002" y2="-0.7874" width="0.1524" layer="51"/>
<wire x1="1.6002" y1="-0.127" x2="1.6002" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="1.6002" y1="-0.508" x2="2.5908" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="-0.508" x2="2.5908" y2="-0.127" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="-0.127" x2="1.6002" y2="-0.127" width="0.1524" layer="51"/>
<wire x1="1.6002" y1="0.508" x2="1.6002" y2="0.127" width="0.1524" layer="51"/>
<wire x1="1.6002" y1="0.127" x2="2.5908" y2="0.127" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="0.127" x2="2.5908" y2="0.508" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="0.508" x2="1.6002" y2="0.508" width="0.1524" layer="51"/>
<wire x1="1.6002" y1="1.1684" x2="1.6002" y2="0.7874" width="0.1524" layer="51"/>
<wire x1="1.6002" y1="0.7874" x2="2.5908" y2="0.7874" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="0.7874" x2="2.5908" y2="1.1684" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="1.1684" x2="1.6002" y2="1.1684" width="0.1524" layer="51"/>
<wire x1="-1.6002" y1="-1.6002" x2="1.6002" y2="-1.6002" width="0.1524" layer="51"/>
<wire x1="1.6002" y1="-0.127" x2="1.6002" y2="0.127" width="0.1524" layer="51"/>
<wire x1="0.3048" y1="1.6002" x2="-0.3048" y2="1.6002" width="0.1524" layer="51"/>
<wire x1="-1.6002" y1="0.7874" x2="-1.6002" y2="-0.7874" width="0.1524" layer="51"/>
<wire x1="0.3048" y1="1.6002" x2="-0.3048" y2="1.6002" width="0.1524" layer="51" curve="-180"/>
<text x="-1.8034" y="0.254" size="1.27" layer="51" ratio="6" rot="SR0">*</text>
<wire x1="-1.6002" y1="3.5052" x2="-1.6002" y2="3.8862" width="0.1524" layer="47"/>
<wire x1="1.6002" y1="3.5052" x2="1.6002" y2="3.8862" width="0.1524" layer="47"/>
<wire x1="-1.6002" y1="3.5052" x2="-2.8702" y2="3.5052" width="0.1524" layer="47"/>
<wire x1="1.6002" y1="3.5052" x2="2.8702" y2="3.5052" width="0.1524" layer="47"/>
<wire x1="-1.6002" y1="3.5052" x2="-1.8542" y2="3.6322" width="0.1524" layer="47"/>
<wire x1="-1.6002" y1="3.5052" x2="-1.8542" y2="3.3782" width="0.1524" layer="47"/>
<wire x1="-1.8542" y1="3.6322" x2="-1.8542" y2="3.3782" width="0.1524" layer="47"/>
<wire x1="1.6002" y1="3.5052" x2="1.8542" y2="3.6322" width="0.1524" layer="47"/>
<wire x1="1.6002" y1="3.5052" x2="1.8542" y2="3.3782" width="0.1524" layer="47"/>
<wire x1="1.8542" y1="3.6322" x2="1.8542" y2="3.3782" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="-3.5052" x2="-2.5908" y2="5.4102" width="0.1524" layer="47"/>
<wire x1="2.5908" y1="5.4102" x2="2.5908" y2="5.7912" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="5.4102" x2="2.5908" y2="5.4102" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="5.4102" x2="-2.3368" y2="5.5372" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="5.4102" x2="-2.3368" y2="5.2832" width="0.1524" layer="47"/>
<wire x1="-2.3368" y1="5.5372" x2="-2.3368" y2="5.2832" width="0.1524" layer="47"/>
<wire x1="2.5908" y1="5.4102" x2="2.3368" y2="5.5372" width="0.1524" layer="47"/>
<wire x1="2.5908" y1="5.4102" x2="2.3368" y2="5.2832" width="0.1524" layer="47"/>
<wire x1="2.3368" y1="5.5372" x2="2.3368" y2="5.2832" width="0.1524" layer="47"/>
<wire x1="4.1402" y1="1.6002" x2="4.5212" y2="1.6002" width="0.1524" layer="47"/>
<wire x1="4.1402" y1="-1.6002" x2="4.5212" y2="-1.6002" width="0.1524" layer="47"/>
<wire x1="4.1402" y1="1.6002" x2="4.1402" y2="2.8702" width="0.1524" layer="47"/>
<wire x1="4.1402" y1="-1.6002" x2="4.1402" y2="-2.8702" width="0.1524" layer="47"/>
<wire x1="4.1402" y1="1.6002" x2="4.0132" y2="1.8542" width="0.1524" layer="47"/>
<wire x1="4.1402" y1="1.6002" x2="4.2672" y2="1.8542" width="0.1524" layer="47"/>
<wire x1="4.0132" y1="1.8542" x2="4.2672" y2="1.8542" width="0.1524" layer="47"/>
<wire x1="4.1402" y1="-1.6002" x2="4.0132" y2="-1.8542" width="0.1524" layer="47"/>
<wire x1="4.1402" y1="-1.6002" x2="4.2672" y2="-1.8542" width="0.1524" layer="47"/>
<wire x1="4.0132" y1="-1.8542" x2="4.2672" y2="-1.8542" width="0.1524" layer="47"/>
<wire x1="-4.7244" y1="0.9652" x2="-5.08" y2="0.9652" width="0.1524" layer="47"/>
<wire x1="-4.7244" y1="0.3302" x2="-5.08" y2="0.3302" width="0.1524" layer="47"/>
<wire x1="-4.7244" y1="0.9652" x2="-4.7244" y2="2.2352" width="0.1524" layer="47"/>
<wire x1="-4.7244" y1="0.3302" x2="-4.7244" y2="-0.9398" width="0.1524" layer="47"/>
<wire x1="-4.7244" y1="0.9652" x2="-4.826" y2="1.2192" width="0.1524" layer="47"/>
<wire x1="-4.7244" y1="0.9652" x2="-4.572" y2="1.2192" width="0.1524" layer="47"/>
<wire x1="-4.826" y1="1.2192" x2="-4.572" y2="1.2192" width="0.1524" layer="47"/>
<wire x1="-4.7244" y1="0.3302" x2="-4.826" y2="0.0762" width="0.1524" layer="47"/>
<wire x1="-4.7244" y1="0.3302" x2="-4.572" y2="0.0762" width="0.1524" layer="47"/>
<wire x1="-4.826" y1="0.0762" x2="-4.572" y2="0.0762" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="-3.5052" x2="-2.5908" y2="-3.8862" width="0.1524" layer="47"/>
<wire x1="-1.778" y1="-3.5052" x2="-1.778" y2="-3.8862" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="-3.5052" x2="-3.8608" y2="-3.5052" width="0.1524" layer="47"/>
<wire x1="-1.778" y1="-3.5052" x2="-0.508" y2="-3.5052" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="-3.5052" x2="-2.8448" y2="-3.3782" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="-3.5052" x2="-2.8448" y2="-3.6322" width="0.1524" layer="47"/>
<wire x1="-2.8448" y1="-3.3782" x2="-2.8448" y2="-3.6322" width="0.1524" layer="47"/>
<wire x1="-1.778" y1="-3.5052" x2="-1.524" y2="-3.3782" width="0.1524" layer="47"/>
<wire x1="-1.778" y1="-3.5052" x2="-1.524" y2="-3.6322" width="0.1524" layer="47"/>
<wire x1="-1.524" y1="-3.3782" x2="-1.524" y2="-3.6322" width="0.1524" layer="47"/>
<text x="-15.2146" y="-6.6802" size="1.27" layer="47" ratio="6" rot="SR0">Default Padstyle: RX60Y17D0T</text>
<text x="-15.5702" y="-8.2042" size="1.27" layer="47" ratio="6" rot="SR0">Pin One Padstyle: RX60Y17D0T</text>
<text x="-14.8082" y="-12.7762" size="1.27" layer="47" ratio="6" rot="SR0">Alt 1 Padstyle: OX60Y90D30P</text>
<text x="-14.8082" y="-14.3002" size="1.27" layer="47" ratio="6" rot="SR0">Alt 2 Padstyle: OX90Y60D30P</text>
<text x="-3.4544" y="4.0132" size="0.635" layer="47" ratio="4" rot="SR0">0.126in/3.2mm</text>
<text x="-4.0386" y="5.9182" size="0.635" layer="47" ratio="4" rot="SR0">0.203in/5.156mm</text>
<text x="4.6482" y="-0.3048" size="0.635" layer="47" ratio="4" rot="SR0">0.126in/3.2mm</text>
<text x="-12.7254" y="0.3302" size="0.635" layer="47" ratio="4" rot="SR0">0.026in/0.65mm</text>
<text x="-6.223" y="-4.6482" size="0.635" layer="47" ratio="4" rot="SR0">0.032in/0.813mm</text>
<wire x1="-1.7272" y1="-1.7272" x2="1.7272" y2="-1.7272" width="0.1524" layer="21"/>
<wire x1="1.7272" y1="-1.7272" x2="1.7272" y2="-1.524" width="0.1524" layer="21"/>
<wire x1="1.7272" y1="1.7272" x2="-1.7272" y2="1.7272" width="0.1524" layer="21"/>
<wire x1="-1.7272" y1="1.7272" x2="-1.7272" y2="1.524" width="0.1524" layer="21"/>
<wire x1="-1.7272" y1="-1.524" x2="-1.7272" y2="-1.7272" width="0.1524" layer="21"/>
<wire x1="1.7272" y1="1.524" x2="1.7272" y2="1.7272" width="0.1524" layer="21"/>
<text x="-2.9972" y="1.27" size="1.27" layer="21" ratio="6" rot="SR0">*</text>
<text x="-3.2766" y="-0.635" size="1.27" layer="27" ratio="6" rot="SR0">&gt;Name</text>
<text x="-1.7272" y="-0.635" size="1.27" layer="27" ratio="6" rot="SR0">&gt;Value</text>
</package>
<package name="RM_8_ADI-M">
<smd name="1" x="-2.2225" y="0.975" dx="1.8288" dy="0.4318" layer="1"/>
<smd name="2" x="-2.2225" y="0.325" dx="1.8288" dy="0.4318" layer="1"/>
<smd name="3" x="-2.2225" y="-0.325" dx="1.8288" dy="0.4318" layer="1"/>
<smd name="4" x="-2.2225" y="-0.975" dx="1.8288" dy="0.4318" layer="1"/>
<smd name="5" x="2.2225" y="-0.975" dx="1.8288" dy="0.4318" layer="1"/>
<smd name="6" x="2.2225" y="-0.325" dx="1.8288" dy="0.4318" layer="1"/>
<smd name="7" x="2.2225" y="0.325" dx="1.8288" dy="0.4318" layer="1"/>
<smd name="8" x="2.2225" y="0.975" dx="1.8288" dy="0.4318" layer="1"/>
<wire x1="1.6002" y1="-1.6002" x2="1.6002" y2="-1.1684" width="0.1524" layer="51"/>
<wire x1="1.6002" y1="-0.7874" x2="1.6002" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="1.6002" y1="-0.127" x2="1.6002" y2="0.127" width="0.1524" layer="51"/>
<wire x1="1.6002" y1="0.508" x2="1.6002" y2="0.7874" width="0.1524" layer="51"/>
<wire x1="1.6002" y1="1.1684" x2="1.6002" y2="1.6002" width="0.1524" layer="51"/>
<wire x1="1.6002" y1="1.6002" x2="0.3048" y2="1.6002" width="0.1524" layer="51"/>
<wire x1="-0.3048" y1="1.6002" x2="-1.6002" y2="1.6002" width="0.1524" layer="51"/>
<wire x1="-1.6002" y1="1.6002" x2="-1.6002" y2="1.1684" width="0.1524" layer="51"/>
<wire x1="-1.6002" y1="0.7874" x2="-1.6002" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-1.6002" y1="0.127" x2="-1.6002" y2="-0.127" width="0.1524" layer="51"/>
<wire x1="-1.6002" y1="-0.508" x2="-1.6002" y2="-0.7874" width="0.1524" layer="51"/>
<wire x1="-1.6002" y1="-1.1684" x2="-1.6002" y2="-1.6002" width="0.1524" layer="51"/>
<wire x1="0.3048" y1="1.6002" x2="-0.3048" y2="1.6002" width="0.1524" layer="51" curve="-180"/>
<text x="-1.8034" y="0.254" size="1.27" layer="51" ratio="6" rot="SR0">*</text>
<wire x1="-1.6002" y1="0" x2="-1.6002" y2="3.5052" width="0.1524" layer="47"/>
<wire x1="1.6002" y1="0" x2="1.6002" y2="3.5052" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="5.4102" x2="-2.5908" y2="5.7912" width="0.1524" layer="47"/>
<wire x1="2.5908" y1="0" x2="2.5908" y2="5.4102" width="0.1524" layer="47"/>
<wire x1="0" y1="1.6002" x2="4.1402" y2="1.6002" width="0.1524" layer="47"/>
<wire x1="0" y1="-1.6002" x2="4.1402" y2="-1.6002" width="0.1524" layer="47"/>
<wire x1="-2.2352" y1="0.9652" x2="-4.7752" y2="0.9652" width="0.1524" layer="47"/>
<wire x1="-2.2352" y1="0.3302" x2="-4.7752" y2="0.3302" width="0.1524" layer="47"/>
<wire x1="-1.778" y1="0" x2="-1.778" y2="-3.5052" width="0.1524" layer="47"/>
<text x="-15.2146" y="-6.6802" size="1.27" layer="47" ratio="6" rot="SR0">Default Padstyle: RX72Y17D0T</text>
<text x="-15.5702" y="-8.2042" size="1.27" layer="47" ratio="6" rot="SR0">Pin One Padstyle: RX72Y17D0T</text>
<text x="-14.8082" y="-12.7762" size="1.27" layer="47" ratio="6" rot="SR0">Alt 1 Padstyle: OX60Y90D30P</text>
<text x="-14.8082" y="-14.3002" size="1.27" layer="47" ratio="6" rot="SR0">Alt 2 Padstyle: OX90Y60D30P</text>
<text x="-3.4544" y="4.0132" size="0.635" layer="47" ratio="4" rot="SR0">0.126in/3.2mm</text>
<text x="-4.0386" y="5.9182" size="0.635" layer="47" ratio="4" rot="SR0">0.203in/5.156mm</text>
<text x="4.6482" y="-0.3048" size="0.635" layer="47" ratio="4" rot="SR0">0.126in/3.2mm</text>
<text x="-12.7762" y="0.3302" size="0.635" layer="47" ratio="4" rot="SR0">0.026in/0.65mm</text>
<text x="-6.223" y="-4.6482" size="0.635" layer="47" ratio="4" rot="SR0">0.032in/0.813mm</text>
<text x="-3.048" y="1.27" size="1.27" layer="21" ratio="6" rot="SR0">*</text>
<text x="-3.2766" y="-0.635" size="1.27" layer="27" ratio="6" rot="SR0">&gt;Name</text>
<text x="-1.7272" y="-0.635" size="1.27" layer="27" ratio="6" rot="SR0">&gt;Value</text>
<wire x1="-1.6002" y1="0.7874" x2="-1.6002" y2="1.1684" width="0.1524" layer="51"/>
<wire x1="-1.6002" y1="1.1684" x2="-2.5908" y2="1.1684" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="1.1684" x2="-2.5908" y2="0.7874" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="0.7874" x2="-1.6002" y2="0.7874" width="0.1524" layer="51"/>
<wire x1="-1.6002" y1="0.127" x2="-1.6002" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-1.6002" y1="0.508" x2="-2.5908" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="0.508" x2="-2.5908" y2="0.127" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="0.127" x2="-1.6002" y2="0.127" width="0.1524" layer="51"/>
<wire x1="-1.6002" y1="-0.508" x2="-1.6002" y2="-0.127" width="0.1524" layer="51"/>
<wire x1="-1.6002" y1="-0.127" x2="-2.5908" y2="-0.127" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="-0.127" x2="-2.5908" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="-0.508" x2="-1.6002" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-1.6002" y1="-1.1684" x2="-1.6002" y2="-0.7874" width="0.1524" layer="51"/>
<wire x1="-1.6002" y1="-0.7874" x2="-2.5908" y2="-0.7874" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="-0.7874" x2="-2.5908" y2="-1.1684" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="-1.1684" x2="-1.6002" y2="-1.1684" width="0.1524" layer="51"/>
<wire x1="1.6002" y1="-0.7874" x2="1.6002" y2="-1.1684" width="0.1524" layer="51"/>
<wire x1="1.6002" y1="-1.1684" x2="2.5908" y2="-1.1684" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="-1.1684" x2="2.5908" y2="-0.7874" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="-0.7874" x2="1.6002" y2="-0.7874" width="0.1524" layer="51"/>
<wire x1="1.6002" y1="-0.127" x2="1.6002" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="1.6002" y1="-0.508" x2="2.5908" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="-0.508" x2="2.5908" y2="-0.127" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="-0.127" x2="1.6002" y2="-0.127" width="0.1524" layer="51"/>
<wire x1="1.6002" y1="0.508" x2="1.6002" y2="0.127" width="0.1524" layer="51"/>
<wire x1="1.6002" y1="0.127" x2="2.5908" y2="0.127" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="0.127" x2="2.5908" y2="0.508" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="0.508" x2="1.6002" y2="0.508" width="0.1524" layer="51"/>
<wire x1="1.6002" y1="1.1684" x2="1.6002" y2="0.7874" width="0.1524" layer="51"/>
<wire x1="1.6002" y1="0.7874" x2="2.5908" y2="0.7874" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="0.7874" x2="2.5908" y2="1.1684" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="1.1684" x2="1.6002" y2="1.1684" width="0.1524" layer="51"/>
<wire x1="-1.6002" y1="-1.6002" x2="1.6002" y2="-1.6002" width="0.1524" layer="51"/>
<wire x1="1.6002" y1="-0.127" x2="1.6002" y2="0.127" width="0.1524" layer="51"/>
<wire x1="0.3048" y1="1.6002" x2="-0.3048" y2="1.6002" width="0.1524" layer="51"/>
<wire x1="-1.6002" y1="0.7874" x2="-1.6002" y2="-0.7874" width="0.1524" layer="51"/>
<wire x1="0.3048" y1="1.6002" x2="-0.3048" y2="1.6002" width="0.1524" layer="51" curve="-180"/>
<text x="-1.8034" y="0.254" size="1.27" layer="51" ratio="6" rot="SR0">*</text>
<wire x1="-1.6002" y1="3.5052" x2="-1.6002" y2="3.8862" width="0.1524" layer="47"/>
<wire x1="1.6002" y1="3.5052" x2="1.6002" y2="3.8862" width="0.1524" layer="47"/>
<wire x1="-1.6002" y1="3.5052" x2="-2.8702" y2="3.5052" width="0.1524" layer="47"/>
<wire x1="1.6002" y1="3.5052" x2="2.8702" y2="3.5052" width="0.1524" layer="47"/>
<wire x1="-1.6002" y1="3.5052" x2="-1.8542" y2="3.6322" width="0.1524" layer="47"/>
<wire x1="-1.6002" y1="3.5052" x2="-1.8542" y2="3.3782" width="0.1524" layer="47"/>
<wire x1="-1.8542" y1="3.6322" x2="-1.8542" y2="3.3782" width="0.1524" layer="47"/>
<wire x1="1.6002" y1="3.5052" x2="1.8542" y2="3.6322" width="0.1524" layer="47"/>
<wire x1="1.6002" y1="3.5052" x2="1.8542" y2="3.3782" width="0.1524" layer="47"/>
<wire x1="1.8542" y1="3.6322" x2="1.8542" y2="3.3782" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="-3.5052" x2="-2.5908" y2="5.4102" width="0.1524" layer="47"/>
<wire x1="2.5908" y1="5.4102" x2="2.5908" y2="5.7912" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="5.4102" x2="2.5908" y2="5.4102" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="5.4102" x2="-2.3368" y2="5.5372" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="5.4102" x2="-2.3368" y2="5.2832" width="0.1524" layer="47"/>
<wire x1="-2.3368" y1="5.5372" x2="-2.3368" y2="5.2832" width="0.1524" layer="47"/>
<wire x1="2.5908" y1="5.4102" x2="2.3368" y2="5.5372" width="0.1524" layer="47"/>
<wire x1="2.5908" y1="5.4102" x2="2.3368" y2="5.2832" width="0.1524" layer="47"/>
<wire x1="2.3368" y1="5.5372" x2="2.3368" y2="5.2832" width="0.1524" layer="47"/>
<wire x1="4.1402" y1="1.6002" x2="4.5212" y2="1.6002" width="0.1524" layer="47"/>
<wire x1="4.1402" y1="-1.6002" x2="4.5212" y2="-1.6002" width="0.1524" layer="47"/>
<wire x1="4.1402" y1="1.6002" x2="4.1402" y2="2.8702" width="0.1524" layer="47"/>
<wire x1="4.1402" y1="-1.6002" x2="4.1402" y2="-2.8702" width="0.1524" layer="47"/>
<wire x1="4.1402" y1="1.6002" x2="4.0132" y2="1.8542" width="0.1524" layer="47"/>
<wire x1="4.1402" y1="1.6002" x2="4.2672" y2="1.8542" width="0.1524" layer="47"/>
<wire x1="4.0132" y1="1.8542" x2="4.2672" y2="1.8542" width="0.1524" layer="47"/>
<wire x1="4.1402" y1="-1.6002" x2="4.0132" y2="-1.8542" width="0.1524" layer="47"/>
<wire x1="4.1402" y1="-1.6002" x2="4.2672" y2="-1.8542" width="0.1524" layer="47"/>
<wire x1="4.0132" y1="-1.8542" x2="4.2672" y2="-1.8542" width="0.1524" layer="47"/>
<wire x1="-4.7752" y1="0.9652" x2="-5.1308" y2="0.9652" width="0.1524" layer="47"/>
<wire x1="-4.7752" y1="0.3302" x2="-5.1308" y2="0.3302" width="0.1524" layer="47"/>
<wire x1="-4.7752" y1="0.9652" x2="-4.7752" y2="2.2352" width="0.1524" layer="47"/>
<wire x1="-4.7752" y1="0.3302" x2="-4.7752" y2="-0.9398" width="0.1524" layer="47"/>
<wire x1="-4.7752" y1="0.9652" x2="-4.8768" y2="1.2192" width="0.1524" layer="47"/>
<wire x1="-4.7752" y1="0.9652" x2="-4.6228" y2="1.2192" width="0.1524" layer="47"/>
<wire x1="-4.8768" y1="1.2192" x2="-4.6228" y2="1.2192" width="0.1524" layer="47"/>
<wire x1="-4.7752" y1="0.3302" x2="-4.8768" y2="0.0762" width="0.1524" layer="47"/>
<wire x1="-4.7752" y1="0.3302" x2="-4.6228" y2="0.0762" width="0.1524" layer="47"/>
<wire x1="-4.8768" y1="0.0762" x2="-4.6228" y2="0.0762" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="-3.5052" x2="-2.5908" y2="-3.8862" width="0.1524" layer="47"/>
<wire x1="-1.778" y1="-3.5052" x2="-1.778" y2="-3.8862" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="-3.5052" x2="-3.8608" y2="-3.5052" width="0.1524" layer="47"/>
<wire x1="-1.778" y1="-3.5052" x2="-0.508" y2="-3.5052" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="-3.5052" x2="-2.8448" y2="-3.3782" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="-3.5052" x2="-2.8448" y2="-3.6322" width="0.1524" layer="47"/>
<wire x1="-2.8448" y1="-3.3782" x2="-2.8448" y2="-3.6322" width="0.1524" layer="47"/>
<wire x1="-1.778" y1="-3.5052" x2="-1.524" y2="-3.3782" width="0.1524" layer="47"/>
<wire x1="-1.778" y1="-3.5052" x2="-1.524" y2="-3.6322" width="0.1524" layer="47"/>
<wire x1="-1.524" y1="-3.3782" x2="-1.524" y2="-3.6322" width="0.1524" layer="47"/>
<text x="-15.2146" y="-6.6802" size="1.27" layer="47" ratio="6" rot="SR0">Default Padstyle: RX72Y17D0T</text>
<text x="-15.5702" y="-8.2042" size="1.27" layer="47" ratio="6" rot="SR0">Pin One Padstyle: RX72Y17D0T</text>
<text x="-14.8082" y="-12.7762" size="1.27" layer="47" ratio="6" rot="SR0">Alt 1 Padstyle: OX60Y90D30P</text>
<text x="-14.8082" y="-14.3002" size="1.27" layer="47" ratio="6" rot="SR0">Alt 2 Padstyle: OX90Y60D30P</text>
<text x="-3.4544" y="4.0132" size="0.635" layer="47" ratio="4" rot="SR0">0.126in/3.2mm</text>
<text x="-4.0386" y="5.9182" size="0.635" layer="47" ratio="4" rot="SR0">0.203in/5.156mm</text>
<text x="4.6482" y="-0.3048" size="0.635" layer="47" ratio="4" rot="SR0">0.126in/3.2mm</text>
<text x="-12.7762" y="0.3302" size="0.635" layer="47" ratio="4" rot="SR0">0.026in/0.65mm</text>
<text x="-6.223" y="-4.6482" size="0.635" layer="47" ratio="4" rot="SR0">0.032in/0.813mm</text>
<wire x1="-1.7272" y1="-1.7272" x2="1.7272" y2="-1.7272" width="0.1524" layer="21"/>
<wire x1="1.7272" y1="1.7272" x2="-1.7272" y2="1.7272" width="0.1524" layer="21"/>
<text x="-3.048" y="1.27" size="1.27" layer="21" ratio="6" rot="SR0">*</text>
<text x="-3.2766" y="-0.635" size="1.27" layer="27" ratio="6" rot="SR0">&gt;Name</text>
<text x="-1.7272" y="-0.635" size="1.27" layer="27" ratio="6" rot="SR0">&gt;Value</text>
</package>
<package name="RM_8_ADI-L">
<smd name="1" x="-2.1209" y="0.975" dx="1.2192" dy="0.381" layer="1"/>
<smd name="2" x="-2.1209" y="0.325" dx="1.2192" dy="0.381" layer="1"/>
<smd name="3" x="-2.1209" y="-0.325" dx="1.2192" dy="0.381" layer="1"/>
<smd name="4" x="-2.1209" y="-0.975" dx="1.2192" dy="0.381" layer="1"/>
<smd name="5" x="2.1209" y="-0.975" dx="1.2192" dy="0.381" layer="1"/>
<smd name="6" x="2.1209" y="-0.325" dx="1.2192" dy="0.381" layer="1"/>
<smd name="7" x="2.1209" y="0.325" dx="1.2192" dy="0.381" layer="1"/>
<smd name="8" x="2.1209" y="0.975" dx="1.2192" dy="0.381" layer="1"/>
<wire x1="1.6002" y1="-1.6002" x2="1.6002" y2="-1.1684" width="0.1524" layer="51"/>
<wire x1="1.6002" y1="-0.7874" x2="1.6002" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="1.6002" y1="-0.127" x2="1.6002" y2="0.127" width="0.1524" layer="51"/>
<wire x1="1.6002" y1="0.508" x2="1.6002" y2="0.7874" width="0.1524" layer="51"/>
<wire x1="1.6002" y1="1.1684" x2="1.6002" y2="1.6002" width="0.1524" layer="51"/>
<wire x1="1.6002" y1="1.6002" x2="0.3048" y2="1.6002" width="0.1524" layer="51"/>
<wire x1="-0.3048" y1="1.6002" x2="-1.6002" y2="1.6002" width="0.1524" layer="51"/>
<wire x1="-1.6002" y1="1.6002" x2="-1.6002" y2="1.1684" width="0.1524" layer="51"/>
<wire x1="-1.6002" y1="0.7874" x2="-1.6002" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-1.6002" y1="0.127" x2="-1.6002" y2="-0.127" width="0.1524" layer="51"/>
<wire x1="-1.6002" y1="-0.508" x2="-1.6002" y2="-0.7874" width="0.1524" layer="51"/>
<wire x1="-1.6002" y1="-1.1684" x2="-1.6002" y2="-1.6002" width="0.1524" layer="51"/>
<wire x1="0.3048" y1="1.6002" x2="-0.3048" y2="1.6002" width="0.1524" layer="51" curve="-180"/>
<text x="-1.8034" y="0.254" size="1.27" layer="51" ratio="6" rot="SR0">*</text>
<wire x1="-1.6002" y1="0" x2="-1.6002" y2="3.5052" width="0.1524" layer="47"/>
<wire x1="1.6002" y1="0" x2="1.6002" y2="3.5052" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="5.4102" x2="-2.5908" y2="5.7912" width="0.1524" layer="47"/>
<wire x1="2.5908" y1="0" x2="2.5908" y2="5.4102" width="0.1524" layer="47"/>
<wire x1="0" y1="1.6002" x2="4.1402" y2="1.6002" width="0.1524" layer="47"/>
<wire x1="0" y1="-1.6002" x2="4.1402" y2="-1.6002" width="0.1524" layer="47"/>
<wire x1="-2.1336" y1="0.9652" x2="-4.6736" y2="0.9652" width="0.1524" layer="47"/>
<wire x1="-2.1336" y1="0.3302" x2="-4.6736" y2="0.3302" width="0.1524" layer="47"/>
<wire x1="-1.778" y1="0" x2="-1.778" y2="-3.5052" width="0.1524" layer="47"/>
<text x="-15.2146" y="-6.6802" size="1.27" layer="47" ratio="6" rot="SR0">Default Padstyle: RX48Y15D0T</text>
<text x="-15.5702" y="-8.2042" size="1.27" layer="47" ratio="6" rot="SR0">Pin One Padstyle: RX48Y15D0T</text>
<text x="-14.8082" y="-12.7762" size="1.27" layer="47" ratio="6" rot="SR0">Alt 1 Padstyle: OX60Y90D30P</text>
<text x="-14.8082" y="-14.3002" size="1.27" layer="47" ratio="6" rot="SR0">Alt 2 Padstyle: OX90Y60D30P</text>
<text x="-3.4544" y="4.0132" size="0.635" layer="47" ratio="4" rot="SR0">0.126in/3.2mm</text>
<text x="-4.0386" y="5.9182" size="0.635" layer="47" ratio="4" rot="SR0">0.203in/5.156mm</text>
<text x="4.6482" y="-0.3048" size="0.635" layer="47" ratio="4" rot="SR0">0.126in/3.2mm</text>
<text x="-12.6746" y="0.3302" size="0.635" layer="47" ratio="4" rot="SR0">0.026in/0.65mm</text>
<text x="-6.223" y="-4.6482" size="0.635" layer="47" ratio="4" rot="SR0">0.032in/0.813mm</text>
<text x="-2.9464" y="1.2192" size="1.27" layer="21" ratio="6" rot="SR0">*</text>
<text x="-3.2766" y="-0.635" size="1.27" layer="27" ratio="6" rot="SR0">&gt;Name</text>
<text x="-1.7272" y="-0.635" size="1.27" layer="27" ratio="6" rot="SR0">&gt;Value</text>
<wire x1="-1.6002" y1="0.7874" x2="-1.6002" y2="1.1684" width="0.1524" layer="51"/>
<wire x1="-1.6002" y1="1.1684" x2="-2.5908" y2="1.1684" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="1.1684" x2="-2.5908" y2="0.7874" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="0.7874" x2="-1.6002" y2="0.7874" width="0.1524" layer="51"/>
<wire x1="-1.6002" y1="0.127" x2="-1.6002" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-1.6002" y1="0.508" x2="-2.5908" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="0.508" x2="-2.5908" y2="0.127" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="0.127" x2="-1.6002" y2="0.127" width="0.1524" layer="51"/>
<wire x1="-1.6002" y1="-0.508" x2="-1.6002" y2="-0.127" width="0.1524" layer="51"/>
<wire x1="-1.6002" y1="-0.127" x2="-2.5908" y2="-0.127" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="-0.127" x2="-2.5908" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="-0.508" x2="-1.6002" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-1.6002" y1="-1.1684" x2="-1.6002" y2="-0.7874" width="0.1524" layer="51"/>
<wire x1="-1.6002" y1="-0.7874" x2="-2.5908" y2="-0.7874" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="-0.7874" x2="-2.5908" y2="-1.1684" width="0.1524" layer="51"/>
<wire x1="-2.5908" y1="-1.1684" x2="-1.6002" y2="-1.1684" width="0.1524" layer="51"/>
<wire x1="1.6002" y1="-0.7874" x2="1.6002" y2="-1.1684" width="0.1524" layer="51"/>
<wire x1="1.6002" y1="-1.1684" x2="2.5908" y2="-1.1684" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="-1.1684" x2="2.5908" y2="-0.7874" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="-0.7874" x2="1.6002" y2="-0.7874" width="0.1524" layer="51"/>
<wire x1="1.6002" y1="-0.127" x2="1.6002" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="1.6002" y1="-0.508" x2="2.5908" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="-0.508" x2="2.5908" y2="-0.127" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="-0.127" x2="1.6002" y2="-0.127" width="0.1524" layer="51"/>
<wire x1="1.6002" y1="0.508" x2="1.6002" y2="0.127" width="0.1524" layer="51"/>
<wire x1="1.6002" y1="0.127" x2="2.5908" y2="0.127" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="0.127" x2="2.5908" y2="0.508" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="0.508" x2="1.6002" y2="0.508" width="0.1524" layer="51"/>
<wire x1="1.6002" y1="1.1684" x2="1.6002" y2="0.7874" width="0.1524" layer="51"/>
<wire x1="1.6002" y1="0.7874" x2="2.5908" y2="0.7874" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="0.7874" x2="2.5908" y2="1.1684" width="0.1524" layer="51"/>
<wire x1="2.5908" y1="1.1684" x2="1.6002" y2="1.1684" width="0.1524" layer="51"/>
<wire x1="-1.6002" y1="-1.6002" x2="1.6002" y2="-1.6002" width="0.1524" layer="51"/>
<wire x1="1.6002" y1="-0.127" x2="1.6002" y2="0.127" width="0.1524" layer="51"/>
<wire x1="0.3048" y1="1.6002" x2="-0.3048" y2="1.6002" width="0.1524" layer="51"/>
<wire x1="-1.6002" y1="0.7874" x2="-1.6002" y2="-0.7874" width="0.1524" layer="51"/>
<wire x1="0.3048" y1="1.6002" x2="-0.3048" y2="1.6002" width="0.1524" layer="51" curve="-180"/>
<text x="-1.8034" y="0.254" size="1.27" layer="51" ratio="6" rot="SR0">*</text>
<wire x1="-1.6002" y1="3.5052" x2="-1.6002" y2="3.8862" width="0.1524" layer="47"/>
<wire x1="1.6002" y1="3.5052" x2="1.6002" y2="3.8862" width="0.1524" layer="47"/>
<wire x1="-1.6002" y1="3.5052" x2="-2.8702" y2="3.5052" width="0.1524" layer="47"/>
<wire x1="1.6002" y1="3.5052" x2="2.8702" y2="3.5052" width="0.1524" layer="47"/>
<wire x1="-1.6002" y1="3.5052" x2="-1.8542" y2="3.6322" width="0.1524" layer="47"/>
<wire x1="-1.6002" y1="3.5052" x2="-1.8542" y2="3.3782" width="0.1524" layer="47"/>
<wire x1="-1.8542" y1="3.6322" x2="-1.8542" y2="3.3782" width="0.1524" layer="47"/>
<wire x1="1.6002" y1="3.5052" x2="1.8542" y2="3.6322" width="0.1524" layer="47"/>
<wire x1="1.6002" y1="3.5052" x2="1.8542" y2="3.3782" width="0.1524" layer="47"/>
<wire x1="1.8542" y1="3.6322" x2="1.8542" y2="3.3782" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="-3.5052" x2="-2.5908" y2="5.4102" width="0.1524" layer="47"/>
<wire x1="2.5908" y1="5.4102" x2="2.5908" y2="5.7912" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="5.4102" x2="2.5908" y2="5.4102" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="5.4102" x2="-2.3368" y2="5.5372" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="5.4102" x2="-2.3368" y2="5.2832" width="0.1524" layer="47"/>
<wire x1="-2.3368" y1="5.5372" x2="-2.3368" y2="5.2832" width="0.1524" layer="47"/>
<wire x1="2.5908" y1="5.4102" x2="2.3368" y2="5.5372" width="0.1524" layer="47"/>
<wire x1="2.5908" y1="5.4102" x2="2.3368" y2="5.2832" width="0.1524" layer="47"/>
<wire x1="2.3368" y1="5.5372" x2="2.3368" y2="5.2832" width="0.1524" layer="47"/>
<wire x1="4.1402" y1="1.6002" x2="4.5212" y2="1.6002" width="0.1524" layer="47"/>
<wire x1="4.1402" y1="-1.6002" x2="4.5212" y2="-1.6002" width="0.1524" layer="47"/>
<wire x1="4.1402" y1="1.6002" x2="4.1402" y2="2.8702" width="0.1524" layer="47"/>
<wire x1="4.1402" y1="-1.6002" x2="4.1402" y2="-2.8702" width="0.1524" layer="47"/>
<wire x1="4.1402" y1="1.6002" x2="4.0132" y2="1.8542" width="0.1524" layer="47"/>
<wire x1="4.1402" y1="1.6002" x2="4.2672" y2="1.8542" width="0.1524" layer="47"/>
<wire x1="4.0132" y1="1.8542" x2="4.2672" y2="1.8542" width="0.1524" layer="47"/>
<wire x1="4.1402" y1="-1.6002" x2="4.0132" y2="-1.8542" width="0.1524" layer="47"/>
<wire x1="4.1402" y1="-1.6002" x2="4.2672" y2="-1.8542" width="0.1524" layer="47"/>
<wire x1="4.0132" y1="-1.8542" x2="4.2672" y2="-1.8542" width="0.1524" layer="47"/>
<wire x1="-4.6736" y1="0.9652" x2="-5.0292" y2="0.9652" width="0.1524" layer="47"/>
<wire x1="-4.6736" y1="0.3302" x2="-5.0292" y2="0.3302" width="0.1524" layer="47"/>
<wire x1="-4.6736" y1="0.9652" x2="-4.6736" y2="2.2352" width="0.1524" layer="47"/>
<wire x1="-4.6736" y1="0.3302" x2="-4.6736" y2="-0.9398" width="0.1524" layer="47"/>
<wire x1="-4.6736" y1="0.9652" x2="-4.7752" y2="1.2192" width="0.1524" layer="47"/>
<wire x1="-4.6736" y1="0.9652" x2="-4.5212" y2="1.2192" width="0.1524" layer="47"/>
<wire x1="-4.7752" y1="1.2192" x2="-4.5212" y2="1.2192" width="0.1524" layer="47"/>
<wire x1="-4.6736" y1="0.3302" x2="-4.7752" y2="0.0762" width="0.1524" layer="47"/>
<wire x1="-4.6736" y1="0.3302" x2="-4.5212" y2="0.0762" width="0.1524" layer="47"/>
<wire x1="-4.7752" y1="0.0762" x2="-4.5212" y2="0.0762" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="-3.5052" x2="-2.5908" y2="-3.8862" width="0.1524" layer="47"/>
<wire x1="-1.778" y1="-3.5052" x2="-1.778" y2="-3.8862" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="-3.5052" x2="-3.8608" y2="-3.5052" width="0.1524" layer="47"/>
<wire x1="-1.778" y1="-3.5052" x2="-0.508" y2="-3.5052" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="-3.5052" x2="-2.8448" y2="-3.3782" width="0.1524" layer="47"/>
<wire x1="-2.5908" y1="-3.5052" x2="-2.8448" y2="-3.6322" width="0.1524" layer="47"/>
<wire x1="-2.8448" y1="-3.3782" x2="-2.8448" y2="-3.6322" width="0.1524" layer="47"/>
<wire x1="-1.778" y1="-3.5052" x2="-1.524" y2="-3.3782" width="0.1524" layer="47"/>
<wire x1="-1.778" y1="-3.5052" x2="-1.524" y2="-3.6322" width="0.1524" layer="47"/>
<wire x1="-1.524" y1="-3.3782" x2="-1.524" y2="-3.6322" width="0.1524" layer="47"/>
<text x="-15.2146" y="-6.6802" size="1.27" layer="47" ratio="6" rot="SR0">Default Padstyle: RX48Y15D0T</text>
<text x="-15.5702" y="-8.2042" size="1.27" layer="47" ratio="6" rot="SR0">Pin One Padstyle: RX48Y15D0T</text>
<text x="-14.8082" y="-12.7762" size="1.27" layer="47" ratio="6" rot="SR0">Alt 1 Padstyle: OX60Y90D30P</text>
<text x="-14.8082" y="-14.3002" size="1.27" layer="47" ratio="6" rot="SR0">Alt 2 Padstyle: OX90Y60D30P</text>
<text x="-3.4544" y="4.0132" size="0.635" layer="47" ratio="4" rot="SR0">0.126in/3.2mm</text>
<text x="-4.0386" y="5.9182" size="0.635" layer="47" ratio="4" rot="SR0">0.203in/5.156mm</text>
<text x="4.6482" y="-0.3048" size="0.635" layer="47" ratio="4" rot="SR0">0.126in/3.2mm</text>
<text x="-12.6746" y="0.3302" size="0.635" layer="47" ratio="4" rot="SR0">0.026in/0.65mm</text>
<text x="-6.223" y="-4.6482" size="0.635" layer="47" ratio="4" rot="SR0">0.032in/0.813mm</text>
<wire x1="-1.7272" y1="-1.7272" x2="1.7272" y2="-1.7272" width="0.1524" layer="21"/>
<wire x1="1.7272" y1="1.7272" x2="-1.7272" y2="1.7272" width="0.1524" layer="21"/>
<text x="-2.9464" y="1.2192" size="1.27" layer="21" ratio="6" rot="SR0">*</text>
<text x="-3.2766" y="-0.635" size="1.27" layer="27" ratio="6" rot="SR0">&gt;Name</text>
<text x="-1.7272" y="-0.635" size="1.27" layer="27" ratio="6" rot="SR0">&gt;Value</text>
</package>
<package name="RGR0020A">
<smd name="1" x="-1.65" y="1" dx="0.6" dy="0.24" layer="1" roundness="100" rot="R180"/>
<smd name="2" x="-1.65" y="0.5" dx="0.6" dy="0.24" layer="1" roundness="100" rot="R180"/>
<smd name="3" x="-1.65" y="0" dx="0.6" dy="0.24" layer="1" roundness="100" rot="R180"/>
<smd name="4" x="-1.65" y="-0.5" dx="0.6" dy="0.24" layer="1" roundness="100" rot="R180"/>
<smd name="5" x="-1.65" y="-1" dx="0.6" dy="0.24" layer="1" roundness="100" rot="R180"/>
<smd name="6" x="-1" y="-1.65" dx="0.6" dy="0.24" layer="1" roundness="100" rot="R90"/>
<smd name="7" x="-0.5" y="-1.65" dx="0.6" dy="0.24" layer="1" roundness="100" rot="R90"/>
<smd name="8" x="0" y="-1.65" dx="0.6" dy="0.24" layer="1" roundness="100" rot="R90"/>
<smd name="9" x="0.5" y="-1.65" dx="0.6" dy="0.24" layer="1" roundness="100" rot="R90"/>
<smd name="10" x="1" y="-1.65" dx="0.6" dy="0.24" layer="1" roundness="100" rot="R90"/>
<smd name="11" x="1.65" y="-1" dx="0.6" dy="0.24" layer="1" roundness="100" rot="R180"/>
<smd name="12" x="1.65" y="-0.5" dx="0.6" dy="0.24" layer="1" roundness="100" rot="R180"/>
<smd name="13" x="1.65" y="0" dx="0.6" dy="0.24" layer="1" roundness="100" rot="R180"/>
<smd name="14" x="1.65" y="0.5" dx="0.6" dy="0.24" layer="1" roundness="100" rot="R180"/>
<smd name="15" x="1.65" y="1" dx="0.6" dy="0.24" layer="1" roundness="100" rot="R180"/>
<smd name="16" x="1" y="1.65" dx="0.6" dy="0.24" layer="1" roundness="100" rot="R90"/>
<smd name="17" x="0.5" y="1.65" dx="0.6" dy="0.24" layer="1" roundness="100" rot="R90"/>
<smd name="18" x="0" y="1.65" dx="0.6" dy="0.24" layer="1" roundness="100" rot="R90"/>
<smd name="19" x="-0.5" y="1.65" dx="0.6" dy="0.24" layer="1" roundness="100" rot="R90"/>
<smd name="20" x="-1" y="1.65" dx="0.6" dy="0.24" layer="1" roundness="100" rot="R90"/>
<smd name="21" x="0" y="0" dx="2.05" dy="2.05" layer="1"/>
<pad name="V" x="0" y="-0.7874" drill="0.2032" diameter="0.508"/>
<pad name="V_1" x="0" y="0.7874" drill="0.2032" diameter="0.508"/>
<pad name="V_2" x="-0.7874" y="0" drill="0.2032" diameter="0.508"/>
<pad name="V_3" x="0.7874" y="0" drill="0.2032" diameter="0.508"/>
<wire x1="-1.9812" y1="-1.9812" x2="-1.778" y2="-1.9812" width="0.2032" layer="21"/>
<wire x1="-1.9812" y1="-1.9812" x2="-1.9812" y2="-1.778" width="0.2032" layer="21"/>
<wire x1="1.778" y1="-1.9812" x2="1.9812" y2="-1.9812" width="0.2032" layer="21"/>
<wire x1="1.9812" y1="-1.9812" x2="1.9812" y2="-1.778" width="0.2032" layer="21"/>
<wire x1="1.9812" y1="1.778" x2="1.9812" y2="1.9812" width="0.2032" layer="21"/>
<wire x1="1.778" y1="1.9812" x2="1.9812" y2="1.9812" width="0.2032" layer="21"/>
<wire x1="-1.9812" y1="1.9812" x2="-1.397" y2="1.9812" width="0.2032" layer="21"/>
<wire x1="-1.9812" y1="1.4224" x2="-1.9812" y2="1.9812" width="0.2032" layer="21"/>
<text x="-1.8288" y="2.7178" size="1.27" layer="21" ratio="6" rot="SR0">Designator250</text>
<wire x1="-1.8288" y1="-1.8288" x2="-1.8288" y2="1.8288" width="0.1524" layer="51"/>
<wire x1="1.8288" y1="-1.8288" x2="1.8288" y2="1.8288" width="0.1524" layer="51"/>
<wire x1="-1.8288" y1="1.8288" x2="1.8288" y2="1.8288" width="0.1524" layer="51"/>
<wire x1="-1.8288" y1="-1.8288" x2="1.8288" y2="-1.8288" width="0.1524" layer="51"/>
<wire x1="-0.8636" y1="0.9144" x2="-1.4732" y2="0.9144" width="0.1016" layer="51" curve="-180"/>
<wire x1="-1.4732" y1="0.9144" x2="-0.8636" y2="0.9144" width="0.1016" layer="51" curve="-180"/>
<polygon width="0.0254" layer="31">
<vertex x="0.1" y="0.1"/>
<vertex x="1.017" y="0.1"/>
<vertex x="1.017" y="1.017"/>
<vertex x="0.1" y="1.017"/>
</polygon>
<polygon width="0.0254" layer="31">
<vertex x="-0.1" y="1.017"/>
<vertex x="-1.017" y="1.017"/>
<vertex x="-1.017" y="0.1"/>
<vertex x="-0.1" y="0.1"/>
</polygon>
<polygon width="0.0254" layer="31">
<vertex x="-0.1" y="-0.1"/>
<vertex x="-1.017" y="-0.1"/>
<vertex x="-1.017" y="-1.017"/>
<vertex x="-0.1" y="-1.017"/>
</polygon>
<polygon width="0.0254" layer="31">
<vertex x="0.1" y="-1.017"/>
<vertex x="1.017" y="-1.017"/>
<vertex x="1.017" y="-0.1"/>
<vertex x="0.1" y="-0.1"/>
</polygon>
<text x="-1.7272" y="-0.635" size="1.27" layer="27" ratio="6" rot="SR0">&gt;Value</text>
<text x="-3.2766" y="-0.635" size="1.27" layer="27" ratio="6" rot="SR0">&gt;Name</text>
</package>
<package name="RGR0020A_NV">
<smd name="1" x="-1.65" y="1" dx="0.6" dy="0.24" layer="1" roundness="100" rot="R180"/>
<smd name="2" x="-1.65" y="0.5" dx="0.6" dy="0.24" layer="1" roundness="100" rot="R180"/>
<smd name="3" x="-1.65" y="0" dx="0.6" dy="0.24" layer="1" roundness="100" rot="R180"/>
<smd name="4" x="-1.65" y="-0.5" dx="0.6" dy="0.24" layer="1" roundness="100" rot="R180"/>
<smd name="5" x="-1.65" y="-1" dx="0.6" dy="0.24" layer="1" roundness="100" rot="R180"/>
<smd name="6" x="-1" y="-1.65" dx="0.6" dy="0.24" layer="1" roundness="100" rot="R90"/>
<smd name="7" x="-0.5" y="-1.65" dx="0.6" dy="0.24" layer="1" roundness="100" rot="R90"/>
<smd name="8" x="0" y="-1.65" dx="0.6" dy="0.24" layer="1" roundness="100" rot="R90"/>
<smd name="9" x="0.5" y="-1.65" dx="0.6" dy="0.24" layer="1" roundness="100" rot="R90"/>
<smd name="10" x="1" y="-1.65" dx="0.6" dy="0.24" layer="1" roundness="100" rot="R90"/>
<smd name="11" x="1.65" y="-1" dx="0.6" dy="0.24" layer="1" roundness="100" rot="R180"/>
<smd name="12" x="1.65" y="-0.5" dx="0.6" dy="0.24" layer="1" roundness="100" rot="R180"/>
<smd name="13" x="1.65" y="0" dx="0.6" dy="0.24" layer="1" roundness="100" rot="R180"/>
<smd name="14" x="1.65" y="0.5" dx="0.6" dy="0.24" layer="1" roundness="100" rot="R180"/>
<smd name="15" x="1.65" y="1" dx="0.6" dy="0.24" layer="1" roundness="100" rot="R180"/>
<smd name="16" x="1" y="1.65" dx="0.6" dy="0.24" layer="1" roundness="100" rot="R90"/>
<smd name="17" x="0.5" y="1.65" dx="0.6" dy="0.24" layer="1" roundness="100" rot="R90"/>
<smd name="18" x="0" y="1.65" dx="0.6" dy="0.24" layer="1" roundness="100" rot="R90"/>
<smd name="19" x="-0.5" y="1.65" dx="0.6" dy="0.24" layer="1" roundness="100" rot="R90"/>
<smd name="20" x="-1" y="1.65" dx="0.6" dy="0.24" layer="1" roundness="100" rot="R90"/>
<smd name="21" x="0" y="0" dx="2.05" dy="2.05" layer="1"/>
<wire x1="-1.9812" y1="-1.9812" x2="-1.778" y2="-1.9812" width="0.2032" layer="21"/>
<wire x1="-1.9812" y1="-1.9812" x2="-1.9812" y2="-1.778" width="0.2032" layer="21"/>
<wire x1="1.778" y1="-1.9812" x2="1.9812" y2="-1.9812" width="0.2032" layer="21"/>
<wire x1="1.9812" y1="-1.9812" x2="1.9812" y2="-1.778" width="0.2032" layer="21"/>
<wire x1="1.9812" y1="1.778" x2="1.9812" y2="1.9812" width="0.2032" layer="21"/>
<wire x1="1.778" y1="1.9812" x2="1.9812" y2="1.9812" width="0.2032" layer="21"/>
<wire x1="-1.9812" y1="1.9812" x2="-1.397" y2="1.9812" width="0.2032" layer="21"/>
<wire x1="-1.9812" y1="1.4224" x2="-1.9812" y2="1.9812" width="0.2032" layer="21"/>
<text x="-1.8288" y="2.7178" size="1.27" layer="21" ratio="6" rot="SR0">Designator251</text>
<wire x1="-1.8288" y1="-1.8288" x2="-1.8288" y2="1.8288" width="0.1524" layer="51"/>
<wire x1="1.8288" y1="-1.8288" x2="1.8288" y2="1.8288" width="0.1524" layer="51"/>
<wire x1="-1.8288" y1="1.8288" x2="1.8288" y2="1.8288" width="0.1524" layer="51"/>
<wire x1="-1.8288" y1="-1.8288" x2="1.8288" y2="-1.8288" width="0.1524" layer="51"/>
<wire x1="-0.8636" y1="0.9144" x2="-1.4732" y2="0.9144" width="0.1016" layer="51" curve="-180"/>
<wire x1="-1.4732" y1="0.9144" x2="-0.8636" y2="0.9144" width="0.1016" layer="51" curve="-180"/>
<polygon width="0.0254" layer="31">
<vertex x="0.1" y="0.1"/>
<vertex x="1.017" y="0.1"/>
<vertex x="1.017" y="1.017"/>
<vertex x="0.1" y="1.017"/>
</polygon>
<polygon width="0.0254" layer="31">
<vertex x="-0.1" y="1.017"/>
<vertex x="-1.017" y="1.017"/>
<vertex x="-1.017" y="0.1"/>
<vertex x="-0.1" y="0.1"/>
</polygon>
<polygon width="0.0254" layer="31">
<vertex x="-0.1" y="-0.1"/>
<vertex x="-1.017" y="-0.1"/>
<vertex x="-1.017" y="-1.017"/>
<vertex x="-0.1" y="-1.017"/>
</polygon>
<polygon width="0.0254" layer="31">
<vertex x="0.1" y="-1.017"/>
<vertex x="1.017" y="-1.017"/>
<vertex x="1.017" y="-0.1"/>
<vertex x="0.1" y="-0.1"/>
</polygon>
<text x="-1.7272" y="-0.635" size="1.27" layer="27" ratio="6" rot="SR0">&gt;Value</text>
<text x="-3.2766" y="-0.635" size="1.27" layer="27" ratio="6" rot="SR0">&gt;Name</text>
</package>
<package name="SOT95P275X130-5N" urn="urn:adsk.eagle:footprint:40998645/1">
<description>5-SOT23, 0.95 mm pitch, 2.75 mm span, 2.90 X 1.60 X 1.30 mm body
&lt;p&gt;5-pin SOT23 package with 0.95 mm pitch, 2.75 mm span with body size 2.90 X 1.60 X 1.30 mm&lt;/p&gt;</description>
<circle x="-1.3281" y="1.7486" radius="0.25" width="0" layer="21"/>
<wire x1="-0.8" y1="1.5586" x2="0.8" y2="1.5586" width="0.12" layer="21"/>
<wire x1="-0.8" y1="-1.5586" x2="0.8" y2="-1.5586" width="0.12" layer="21"/>
<wire x1="0.8" y1="-1.55" x2="-0.8" y2="-1.55" width="0.12" layer="51"/>
<wire x1="-0.8" y1="-1.55" x2="-0.8" y2="1.55" width="0.12" layer="51"/>
<wire x1="-0.8" y1="1.55" x2="0.8" y2="1.55" width="0.12" layer="51"/>
<wire x1="0.8" y1="1.55" x2="0.8" y2="-1.55" width="0.12" layer="51"/>
<smd name="1" x="-1.25" y="0.95" dx="1.2123" dy="0.5891" layer="1"/>
<smd name="2" x="-1.25" y="0" dx="1.2123" dy="0.5891" layer="1"/>
<smd name="3" x="-1.25" y="-0.95" dx="1.2123" dy="0.5891" layer="1"/>
<smd name="4" x="1.25" y="-0.95" dx="1.2123" dy="0.5891" layer="1"/>
<smd name="5" x="1.25" y="0.95" dx="1.2123" dy="0.5891" layer="1"/>
<text x="0" y="2.6336" size="1.27" layer="25" align="bottom-center">&gt;NAME</text>
<text x="0" y="-2.1936" size="1.27" layer="27" align="top-center">&gt;VALUE</text>
</package>
<package name="SOT23-5_TS881_TEX">
<smd name="1" x="-1.27635" y="0.95" dx="0.9525" dy="0.508" layer="1"/>
<smd name="2" x="-1.27635" y="0" dx="0.9525" dy="0.508" layer="1"/>
<smd name="3" x="-1.27635" y="-0.95" dx="0.9525" dy="0.508" layer="1"/>
<smd name="4" x="1.27635" y="-0.95" dx="0.9525" dy="0.508" layer="1"/>
<smd name="5" x="1.27635" y="0.95" dx="0.9525" dy="0.508" layer="1"/>
<wire x1="-0.8128" y1="0.6858" x2="-0.8128" y2="1.1938" width="0.1524" layer="51"/>
<wire x1="-0.8128" y1="1.1938" x2="-1.397" y2="1.1938" width="0.1524" layer="51"/>
<wire x1="-1.397" y1="1.1938" x2="-1.397" y2="0.6858" width="0.1524" layer="51"/>
<wire x1="-1.397" y1="0.6858" x2="-0.8128" y2="0.6858" width="0.1524" layer="51"/>
<wire x1="-0.8128" y1="-0.254" x2="-0.8128" y2="0.254" width="0.1524" layer="51"/>
<wire x1="-0.8128" y1="0.254" x2="-1.397" y2="0.254" width="0.1524" layer="51"/>
<wire x1="-1.397" y1="0.254" x2="-1.397" y2="-0.254" width="0.1524" layer="51"/>
<wire x1="-1.397" y1="-0.254" x2="-0.8128" y2="-0.254" width="0.1524" layer="51"/>
<wire x1="-0.8128" y1="-1.1938" x2="-0.8128" y2="-0.6858" width="0.1524" layer="51"/>
<wire x1="-0.8128" y1="-0.6858" x2="-1.397" y2="-0.6858" width="0.1524" layer="51"/>
<wire x1="-1.397" y1="-0.6858" x2="-1.397" y2="-1.1938" width="0.1524" layer="51"/>
<wire x1="-1.397" y1="-1.1938" x2="-0.8128" y2="-1.1938" width="0.1524" layer="51"/>
<wire x1="0.8128" y1="-0.6858" x2="0.8128" y2="-1.1938" width="0.1524" layer="51"/>
<wire x1="0.8128" y1="-1.1938" x2="1.397" y2="-1.1938" width="0.1524" layer="51"/>
<wire x1="1.397" y1="-1.1938" x2="1.397" y2="-0.6858" width="0.1524" layer="51"/>
<wire x1="1.397" y1="-0.6858" x2="0.8128" y2="-0.6858" width="0.1524" layer="51"/>
<wire x1="0.8128" y1="1.1938" x2="0.8128" y2="0.6858" width="0.1524" layer="51"/>
<wire x1="0.8128" y1="0.6858" x2="1.397" y2="0.6858" width="0.1524" layer="51"/>
<wire x1="1.397" y1="0.6858" x2="1.397" y2="1.1938" width="0.1524" layer="51"/>
<wire x1="1.397" y1="1.1938" x2="0.8128" y2="1.1938" width="0.1524" layer="51"/>
<wire x1="-0.8128" y1="-1.4478" x2="0.8128" y2="-1.4478" width="0.1524" layer="51"/>
<wire x1="0.8128" y1="-1.4478" x2="0.8128" y2="1.4478" width="0.1524" layer="51"/>
<wire x1="0.8128" y1="1.4478" x2="0.3048" y2="1.4478" width="0.1524" layer="51"/>
<wire x1="0.3048" y1="1.4478" x2="-0.3048" y2="1.4478" width="0.1524" layer="51"/>
<wire x1="-0.3048" y1="1.4478" x2="-0.8128" y2="1.4478" width="0.1524" layer="51"/>
<wire x1="-0.8128" y1="1.4478" x2="-0.8128" y2="-1.4478" width="0.1524" layer="51"/>
<wire x1="0.3048" y1="1.4478" x2="-0.3048" y2="1.4478" width="0.1524" layer="51" curve="-180"/>
<text x="-1.1176" y="0.2286" size="1.27" layer="51" ratio="6" rot="SR0">*</text>
<wire x1="-0.8128" y1="3.3528" x2="-0.8128" y2="3.7338" width="0.1524" layer="47"/>
<wire x1="0.8128" y1="0" x2="0.8128" y2="3.3528" width="0.1524" layer="47"/>
<wire x1="0.8128" y1="3.3528" x2="0.8128" y2="3.7338" width="0.1524" layer="47"/>
<wire x1="-0.8128" y1="3.3528" x2="-2.0828" y2="3.3528" width="0.1524" layer="47"/>
<wire x1="0.8128" y1="3.3528" x2="2.0828" y2="3.3528" width="0.1524" layer="47"/>
<wire x1="-0.8128" y1="3.3528" x2="-1.0668" y2="3.4798" width="0.1524" layer="47"/>
<wire x1="-0.8128" y1="3.3528" x2="-1.0668" y2="3.2258" width="0.1524" layer="47"/>
<wire x1="-1.0668" y1="3.4798" x2="-1.0668" y2="3.2258" width="0.1524" layer="47"/>
<wire x1="0.8128" y1="3.3528" x2="1.0668" y2="3.4798" width="0.1524" layer="47"/>
<wire x1="0.8128" y1="3.3528" x2="1.0668" y2="3.2258" width="0.1524" layer="47"/>
<wire x1="1.0668" y1="3.4798" x2="1.0668" y2="3.2258" width="0.1524" layer="47"/>
<wire x1="-1.397" y1="0" x2="-1.397" y2="5.2578" width="0.1524" layer="47"/>
<wire x1="-1.397" y1="5.2578" x2="-1.397" y2="5.6388" width="0.1524" layer="47"/>
<wire x1="1.397" y1="0" x2="1.397" y2="5.2578" width="0.1524" layer="47"/>
<wire x1="1.397" y1="5.2578" x2="1.397" y2="5.6388" width="0.1524" layer="47"/>
<wire x1="-1.397" y1="5.2578" x2="-2.667" y2="5.2578" width="0.1524" layer="47"/>
<wire x1="1.397" y1="5.2578" x2="2.667" y2="5.2578" width="0.1524" layer="47"/>
<wire x1="-1.397" y1="5.2578" x2="-1.651" y2="5.3848" width="0.1524" layer="47"/>
<wire x1="-1.397" y1="5.2578" x2="-1.651" y2="5.1308" width="0.1524" layer="47"/>
<wire x1="-1.651" y1="5.3848" x2="-1.651" y2="5.1308" width="0.1524" layer="47"/>
<wire x1="1.397" y1="5.2578" x2="1.651" y2="5.3848" width="0.1524" layer="47"/>
<wire x1="1.397" y1="5.2578" x2="1.651" y2="5.1308" width="0.1524" layer="47"/>
<wire x1="1.651" y1="5.3848" x2="1.651" y2="5.1308" width="0.1524" layer="47"/>
<wire x1="0" y1="1.4478" x2="8.4328" y2="1.4478" width="0.1524" layer="47"/>
<wire x1="8.4328" y1="1.4478" x2="8.7884" y2="1.4478" width="0.1524" layer="47"/>
<wire x1="0" y1="-1.4478" x2="8.4328" y2="-1.4478" width="0.1524" layer="47"/>
<wire x1="8.4328" y1="-1.4478" x2="8.7884" y2="-1.4478" width="0.1524" layer="47"/>
<wire x1="8.4328" y1="1.4478" x2="8.4328" y2="2.7178" width="0.1524" layer="47"/>
<wire x1="8.4328" y1="-1.4478" x2="8.4328" y2="-2.7178" width="0.1524" layer="47"/>
<wire x1="8.4328" y1="1.4478" x2="8.2804" y2="1.7018" width="0.1524" layer="47"/>
<wire x1="8.4328" y1="1.4478" x2="8.5344" y2="1.7018" width="0.1524" layer="47"/>
<wire x1="8.2804" y1="1.7018" x2="8.5344" y2="1.7018" width="0.1524" layer="47"/>
<wire x1="8.4328" y1="-1.4478" x2="8.2804" y2="-1.7018" width="0.1524" layer="47"/>
<wire x1="8.4328" y1="-1.4478" x2="8.5344" y2="-1.7018" width="0.1524" layer="47"/>
<wire x1="8.2804" y1="-1.7018" x2="8.5344" y2="-1.7018" width="0.1524" layer="47"/>
<wire x1="-1.27" y1="0.9398" x2="-3.81" y2="0.9398" width="0.1524" layer="47"/>
<wire x1="-3.81" y1="0.9398" x2="-4.191" y2="0.9398" width="0.1524" layer="47"/>
<wire x1="-1.27" y1="0" x2="-1.397" y2="0" width="0.1524" layer="47"/>
<wire x1="-1.397" y1="0" x2="-3.81" y2="0" width="0.1524" layer="47"/>
<wire x1="-3.81" y1="0" x2="-4.191" y2="0" width="0.1524" layer="47"/>
<wire x1="-3.81" y1="0.9398" x2="-3.81" y2="2.2098" width="0.1524" layer="47"/>
<wire x1="-3.81" y1="0" x2="-3.81" y2="-1.27" width="0.1524" layer="47"/>
<wire x1="-3.81" y1="0.9398" x2="-3.937" y2="1.1938" width="0.1524" layer="47"/>
<wire x1="-3.81" y1="0.9398" x2="-3.683" y2="1.1938" width="0.1524" layer="47"/>
<wire x1="-3.937" y1="1.1938" x2="-3.683" y2="1.1938" width="0.1524" layer="47"/>
<wire x1="-3.81" y1="0" x2="-3.937" y2="-0.254" width="0.1524" layer="47"/>
<wire x1="-3.81" y1="0" x2="-3.683" y2="-0.254" width="0.1524" layer="47"/>
<wire x1="-3.937" y1="-0.254" x2="-3.683" y2="-0.254" width="0.1524" layer="47"/>
<wire x1="1.27" y1="0.9398" x2="3.81" y2="0.9398" width="0.1524" layer="47"/>
<wire x1="3.81" y1="0.9398" x2="4.191" y2="0.9398" width="0.1524" layer="47"/>
<wire x1="1.27" y1="-0.9398" x2="3.81" y2="-0.9398" width="0.1524" layer="47"/>
<wire x1="3.81" y1="-0.9398" x2="4.191" y2="-0.9398" width="0.1524" layer="47"/>
<wire x1="3.81" y1="0.9398" x2="3.81" y2="2.2098" width="0.1524" layer="47"/>
<wire x1="3.81" y1="-0.9398" x2="3.81" y2="-2.2098" width="0.1524" layer="47"/>
<wire x1="3.81" y1="0.9398" x2="3.683" y2="1.1938" width="0.1524" layer="47"/>
<wire x1="3.81" y1="0.9398" x2="3.937" y2="1.1938" width="0.1524" layer="47"/>
<wire x1="3.683" y1="1.1938" x2="3.937" y2="1.1938" width="0.1524" layer="47"/>
<wire x1="3.81" y1="-0.9398" x2="3.683" y2="-1.1938" width="0.1524" layer="47"/>
<wire x1="3.81" y1="-0.9398" x2="3.937" y2="-1.1938" width="0.1524" layer="47"/>
<wire x1="3.683" y1="-1.1938" x2="3.937" y2="-1.1938" width="0.1524" layer="47"/>
<wire x1="-1.397" y1="0" x2="-1.397" y2="-3.3528" width="0.1524" layer="47"/>
<wire x1="-1.397" y1="-3.3528" x2="-1.397" y2="-3.7338" width="0.1524" layer="47"/>
<wire x1="-0.8128" y1="3.3528" x2="-0.8128" y2="-3.3528" width="0.1524" layer="47"/>
<wire x1="-0.8128" y1="-3.3528" x2="-0.8128" y2="-3.7338" width="0.1524" layer="47"/>
<wire x1="-1.397" y1="-3.3528" x2="-2.667" y2="-3.3528" width="0.1524" layer="47"/>
<wire x1="-0.8128" y1="-3.3528" x2="0.4572" y2="-3.3528" width="0.1524" layer="47"/>
<wire x1="-1.397" y1="-3.3528" x2="-1.651" y2="-3.2258" width="0.1524" layer="47"/>
<wire x1="-1.397" y1="-3.3528" x2="-1.651" y2="-3.4798" width="0.1524" layer="47"/>
<wire x1="-1.651" y1="-3.2258" x2="-1.651" y2="-3.4798" width="0.1524" layer="47"/>
<wire x1="-0.8128" y1="-3.3528" x2="-0.5588" y2="-3.2258" width="0.1524" layer="47"/>
<wire x1="-0.8128" y1="-3.3528" x2="-0.5588" y2="-3.4798" width="0.1524" layer="47"/>
<wire x1="-0.5588" y1="-3.2258" x2="-0.5588" y2="-3.4798" width="0.1524" layer="47"/>
<text x="-16.7386" y="-8.0518" size="1.27" layer="47" ratio="6" rot="SR0">Pin One Padstyle: RX37p5Y20D0T</text>
<text x="-16.3576" y="-6.5278" size="1.27" layer="47" ratio="6" rot="SR0">Default Padstyle: RX37p5Y20D0T</text>
<text x="-14.8082" y="-12.6238" size="1.27" layer="47" ratio="6" rot="SR0">Alt 1 Padstyle: OX60Y90D30P</text>
<text x="-14.8082" y="-14.1478" size="1.27" layer="47" ratio="6" rot="SR0">Alt 2 Padstyle: OX90Y60D30P</text>
<text x="-3.4544" y="3.8608" size="0.635" layer="47" ratio="4" rot="SR0">0.063in/1.6mm</text>
<text x="-3.7592" y="5.7658" size="0.635" layer="47" ratio="4" rot="SR0">0.11in/2.794mm</text>
<text x="8.9408" y="-0.3048" size="0.635" layer="47" ratio="4" rot="SR0">0.114in/2.896mm</text>
<text x="-11.8364" y="0.1524" size="0.635" layer="47" ratio="4" rot="SR0">0.037in/0.95mm</text>
<text x="4.318" y="-0.3048" size="0.635" layer="47" ratio="4" rot="SR0">0.075in/1.9mm</text>
<text x="-4.8514" y="-4.4958" size="0.635" layer="47" ratio="4" rot="SR0">0.024in/0.61mm</text>
<wire x1="-0.9144" y1="-1.5748" x2="0.9144" y2="-1.5748" width="0.1524" layer="21"/>
<wire x1="0.9144" y1="-0.3556" x2="0.9144" y2="0.3556" width="0.1524" layer="21"/>
<wire x1="0.9144" y1="1.5748" x2="-0.9144" y2="1.5748" width="0.1524" layer="21"/>
<text x="-2.1082" y="1.3208" size="1.27" layer="21" ratio="6" rot="SR0">*</text>
<text x="-3.2766" y="-0.635" size="1.27" layer="27" ratio="6" rot="SR0">&gt;Name</text>
<text x="-1.7272" y="-0.635" size="1.27" layer="27" ratio="6" rot="SR0">&gt;Value</text>
</package>
<package name="SOT23-5_TS881_TEX-M">
<smd name="1" x="-1.37795" y="0.95" dx="1.1557" dy="0.508" layer="1"/>
<smd name="2" x="-1.37795" y="0" dx="1.1557" dy="0.508" layer="1"/>
<smd name="3" x="-1.37795" y="-0.95" dx="1.1557" dy="0.508" layer="1"/>
<smd name="4" x="1.37795" y="-0.95" dx="1.1557" dy="0.508" layer="1"/>
<smd name="5" x="1.37795" y="0.95" dx="1.1557" dy="0.508" layer="1"/>
<wire x1="-0.8128" y1="0.6858" x2="-0.8128" y2="1.1938" width="0.1524" layer="51"/>
<wire x1="-0.8128" y1="1.1938" x2="-1.397" y2="1.1938" width="0.1524" layer="51"/>
<wire x1="-1.397" y1="1.1938" x2="-1.397" y2="0.6858" width="0.1524" layer="51"/>
<wire x1="-1.397" y1="0.6858" x2="-0.8128" y2="0.6858" width="0.1524" layer="51"/>
<wire x1="-0.8128" y1="-0.254" x2="-0.8128" y2="0.254" width="0.1524" layer="51"/>
<wire x1="-0.8128" y1="0.254" x2="-1.397" y2="0.254" width="0.1524" layer="51"/>
<wire x1="-1.397" y1="0.254" x2="-1.397" y2="-0.254" width="0.1524" layer="51"/>
<wire x1="-1.397" y1="-0.254" x2="-0.8128" y2="-0.254" width="0.1524" layer="51"/>
<wire x1="-0.8128" y1="-1.1938" x2="-0.8128" y2="-0.6858" width="0.1524" layer="51"/>
<wire x1="-0.8128" y1="-0.6858" x2="-1.397" y2="-0.6858" width="0.1524" layer="51"/>
<wire x1="-1.397" y1="-0.6858" x2="-1.397" y2="-1.1938" width="0.1524" layer="51"/>
<wire x1="-1.397" y1="-1.1938" x2="-0.8128" y2="-1.1938" width="0.1524" layer="51"/>
<wire x1="0.8128" y1="-0.6858" x2="0.8128" y2="-1.1938" width="0.1524" layer="51"/>
<wire x1="0.8128" y1="-1.1938" x2="1.397" y2="-1.1938" width="0.1524" layer="51"/>
<wire x1="1.397" y1="-1.1938" x2="1.397" y2="-0.6858" width="0.1524" layer="51"/>
<wire x1="1.397" y1="-0.6858" x2="0.8128" y2="-0.6858" width="0.1524" layer="51"/>
<wire x1="0.8128" y1="1.1938" x2="0.8128" y2="0.6858" width="0.1524" layer="51"/>
<wire x1="0.8128" y1="0.6858" x2="1.397" y2="0.6858" width="0.1524" layer="51"/>
<wire x1="1.397" y1="0.6858" x2="1.397" y2="1.1938" width="0.1524" layer="51"/>
<wire x1="1.397" y1="1.1938" x2="0.8128" y2="1.1938" width="0.1524" layer="51"/>
<wire x1="-0.8128" y1="-1.4478" x2="0.8128" y2="-1.4478" width="0.1524" layer="51"/>
<wire x1="0.8128" y1="-1.4478" x2="0.8128" y2="1.4478" width="0.1524" layer="51"/>
<wire x1="0.8128" y1="1.4478" x2="0.3048" y2="1.4478" width="0.1524" layer="51"/>
<wire x1="0.3048" y1="1.4478" x2="-0.3048" y2="1.4478" width="0.1524" layer="51"/>
<wire x1="-0.3048" y1="1.4478" x2="-0.8128" y2="1.4478" width="0.1524" layer="51"/>
<wire x1="-0.8128" y1="1.4478" x2="-0.8128" y2="-1.4478" width="0.1524" layer="51"/>
<wire x1="0.3048" y1="1.4478" x2="-0.3048" y2="1.4478" width="0.1524" layer="51" curve="-180"/>
<text x="-1.1176" y="0.2286" size="1.27" layer="51" ratio="6" rot="SR0">*</text>
<wire x1="-0.8128" y1="3.3528" x2="-0.8128" y2="3.7338" width="0.1524" layer="47"/>
<wire x1="0.8128" y1="0" x2="0.8128" y2="3.3528" width="0.1524" layer="47"/>
<wire x1="0.8128" y1="3.3528" x2="0.8128" y2="3.7338" width="0.1524" layer="47"/>
<wire x1="-0.8128" y1="3.3528" x2="-2.0828" y2="3.3528" width="0.1524" layer="47"/>
<wire x1="0.8128" y1="3.3528" x2="2.0828" y2="3.3528" width="0.1524" layer="47"/>
<wire x1="-0.8128" y1="3.3528" x2="-1.0668" y2="3.4798" width="0.1524" layer="47"/>
<wire x1="-0.8128" y1="3.3528" x2="-1.0668" y2="3.2258" width="0.1524" layer="47"/>
<wire x1="-1.0668" y1="3.4798" x2="-1.0668" y2="3.2258" width="0.1524" layer="47"/>
<wire x1="0.8128" y1="3.3528" x2="1.0668" y2="3.4798" width="0.1524" layer="47"/>
<wire x1="0.8128" y1="3.3528" x2="1.0668" y2="3.2258" width="0.1524" layer="47"/>
<wire x1="1.0668" y1="3.4798" x2="1.0668" y2="3.2258" width="0.1524" layer="47"/>
<wire x1="-1.397" y1="0" x2="-1.397" y2="5.2578" width="0.1524" layer="47"/>
<wire x1="-1.397" y1="5.2578" x2="-1.397" y2="5.6388" width="0.1524" layer="47"/>
<wire x1="1.397" y1="0" x2="1.397" y2="5.2578" width="0.1524" layer="47"/>
<wire x1="1.397" y1="5.2578" x2="1.397" y2="5.6388" width="0.1524" layer="47"/>
<wire x1="-1.397" y1="5.2578" x2="-2.667" y2="5.2578" width="0.1524" layer="47"/>
<wire x1="1.397" y1="5.2578" x2="2.667" y2="5.2578" width="0.1524" layer="47"/>
<wire x1="-1.397" y1="5.2578" x2="-1.651" y2="5.3848" width="0.1524" layer="47"/>
<wire x1="-1.397" y1="5.2578" x2="-1.651" y2="5.1308" width="0.1524" layer="47"/>
<wire x1="-1.651" y1="5.3848" x2="-1.651" y2="5.1308" width="0.1524" layer="47"/>
<wire x1="1.397" y1="5.2578" x2="1.651" y2="5.3848" width="0.1524" layer="47"/>
<wire x1="1.397" y1="5.2578" x2="1.651" y2="5.1308" width="0.1524" layer="47"/>
<wire x1="1.651" y1="5.3848" x2="1.651" y2="5.1308" width="0.1524" layer="47"/>
<wire x1="0" y1="1.4478" x2="8.4328" y2="1.4478" width="0.1524" layer="47"/>
<wire x1="8.4328" y1="1.4478" x2="8.7884" y2="1.4478" width="0.1524" layer="47"/>
<wire x1="0" y1="-1.4478" x2="8.4328" y2="-1.4478" width="0.1524" layer="47"/>
<wire x1="8.4328" y1="-1.4478" x2="8.7884" y2="-1.4478" width="0.1524" layer="47"/>
<wire x1="8.4328" y1="1.4478" x2="8.4328" y2="2.7178" width="0.1524" layer="47"/>
<wire x1="8.4328" y1="-1.4478" x2="8.4328" y2="-2.7178" width="0.1524" layer="47"/>
<wire x1="8.4328" y1="1.4478" x2="8.2804" y2="1.7018" width="0.1524" layer="47"/>
<wire x1="8.4328" y1="1.4478" x2="8.5344" y2="1.7018" width="0.1524" layer="47"/>
<wire x1="8.2804" y1="1.7018" x2="8.5344" y2="1.7018" width="0.1524" layer="47"/>
<wire x1="8.4328" y1="-1.4478" x2="8.2804" y2="-1.7018" width="0.1524" layer="47"/>
<wire x1="8.4328" y1="-1.4478" x2="8.5344" y2="-1.7018" width="0.1524" layer="47"/>
<wire x1="8.2804" y1="-1.7018" x2="8.5344" y2="-1.7018" width="0.1524" layer="47"/>
<wire x1="-1.3716" y1="0.9398" x2="-3.9116" y2="0.9398" width="0.1524" layer="47"/>
<wire x1="-3.9116" y1="0.9398" x2="-4.2926" y2="0.9398" width="0.1524" layer="47"/>
<wire x1="-1.3716" y1="0" x2="-1.397" y2="0" width="0.1524" layer="47"/>
<wire x1="-1.397" y1="0" x2="-3.9116" y2="0" width="0.1524" layer="47"/>
<wire x1="-3.9116" y1="0" x2="-4.2926" y2="0" width="0.1524" layer="47"/>
<wire x1="-3.9116" y1="0.9398" x2="-3.9116" y2="2.2098" width="0.1524" layer="47"/>
<wire x1="-3.9116" y1="0" x2="-3.9116" y2="-1.27" width="0.1524" layer="47"/>
<wire x1="-3.9116" y1="0.9398" x2="-4.0386" y2="1.1938" width="0.1524" layer="47"/>
<wire x1="-3.9116" y1="0.9398" x2="-3.7846" y2="1.1938" width="0.1524" layer="47"/>
<wire x1="-4.0386" y1="1.1938" x2="-3.7846" y2="1.1938" width="0.1524" layer="47"/>
<wire x1="-3.9116" y1="0" x2="-4.0386" y2="-0.254" width="0.1524" layer="47"/>
<wire x1="-3.9116" y1="0" x2="-3.7846" y2="-0.254" width="0.1524" layer="47"/>
<wire x1="-4.0386" y1="-0.254" x2="-3.7846" y2="-0.254" width="0.1524" layer="47"/>
<wire x1="1.3716" y1="0.9398" x2="3.9116" y2="0.9398" width="0.1524" layer="47"/>
<wire x1="3.9116" y1="0.9398" x2="4.2926" y2="0.9398" width="0.1524" layer="47"/>
<wire x1="1.3716" y1="-0.9398" x2="3.9116" y2="-0.9398" width="0.1524" layer="47"/>
<wire x1="3.9116" y1="-0.9398" x2="4.2926" y2="-0.9398" width="0.1524" layer="47"/>
<wire x1="3.9116" y1="0.9398" x2="3.9116" y2="2.2098" width="0.1524" layer="47"/>
<wire x1="3.9116" y1="-0.9398" x2="3.9116" y2="-2.2098" width="0.1524" layer="47"/>
<wire x1="3.9116" y1="0.9398" x2="3.7846" y2="1.1938" width="0.1524" layer="47"/>
<wire x1="3.9116" y1="0.9398" x2="4.0386" y2="1.1938" width="0.1524" layer="47"/>
<wire x1="3.7846" y1="1.1938" x2="4.0386" y2="1.1938" width="0.1524" layer="47"/>
<wire x1="3.9116" y1="-0.9398" x2="3.7846" y2="-1.1938" width="0.1524" layer="47"/>
<wire x1="3.9116" y1="-0.9398" x2="4.0386" y2="-1.1938" width="0.1524" layer="47"/>
<wire x1="3.7846" y1="-1.1938" x2="4.0386" y2="-1.1938" width="0.1524" layer="47"/>
<wire x1="-1.397" y1="0" x2="-1.397" y2="-3.3528" width="0.1524" layer="47"/>
<wire x1="-1.397" y1="-3.3528" x2="-1.397" y2="-3.7338" width="0.1524" layer="47"/>
<wire x1="-0.8128" y1="3.3528" x2="-0.8128" y2="-3.3528" width="0.1524" layer="47"/>
<wire x1="-0.8128" y1="-3.3528" x2="-0.8128" y2="-3.7338" width="0.1524" layer="47"/>
<wire x1="-1.397" y1="-3.3528" x2="-2.667" y2="-3.3528" width="0.1524" layer="47"/>
<wire x1="-0.8128" y1="-3.3528" x2="0.4572" y2="-3.3528" width="0.1524" layer="47"/>
<wire x1="-1.397" y1="-3.3528" x2="-1.651" y2="-3.2258" width="0.1524" layer="47"/>
<wire x1="-1.397" y1="-3.3528" x2="-1.651" y2="-3.4798" width="0.1524" layer="47"/>
<wire x1="-1.651" y1="-3.2258" x2="-1.651" y2="-3.4798" width="0.1524" layer="47"/>
<wire x1="-0.8128" y1="-3.3528" x2="-0.5588" y2="-3.2258" width="0.1524" layer="47"/>
<wire x1="-0.8128" y1="-3.3528" x2="-0.5588" y2="-3.4798" width="0.1524" layer="47"/>
<wire x1="-0.5588" y1="-3.2258" x2="-0.5588" y2="-3.4798" width="0.1524" layer="47"/>
<text x="-16.7386" y="-8.0518" size="1.27" layer="47" ratio="6" rot="SR0">Pin One Padstyle: RX45p5Y20D0T</text>
<text x="-16.3576" y="-6.5278" size="1.27" layer="47" ratio="6" rot="SR0">Default Padstyle: RX45p5Y20D0T</text>
<text x="-14.8082" y="-12.6238" size="1.27" layer="47" ratio="6" rot="SR0">Alt 1 Padstyle: OX60Y90D30P</text>
<text x="-14.8082" y="-14.1478" size="1.27" layer="47" ratio="6" rot="SR0">Alt 2 Padstyle: OX90Y60D30P</text>
<text x="-3.4544" y="3.8608" size="0.635" layer="47" ratio="4" rot="SR0">0.063in/1.6mm</text>
<text x="-3.7592" y="5.7658" size="0.635" layer="47" ratio="4" rot="SR0">0.11in/2.794mm</text>
<text x="8.9408" y="-0.3048" size="0.635" layer="47" ratio="4" rot="SR0">0.114in/2.896mm</text>
<text x="-11.938" y="0.1524" size="0.635" layer="47" ratio="4" rot="SR0">0.037in/0.95mm</text>
<text x="4.4196" y="-0.3048" size="0.635" layer="47" ratio="4" rot="SR0">0.075in/1.9mm</text>
<text x="-4.8514" y="-4.4958" size="0.635" layer="47" ratio="4" rot="SR0">0.024in/0.61mm</text>
<wire x1="-0.9144" y1="-1.5748" x2="0.9144" y2="-1.5748" width="0.1524" layer="21"/>
<wire x1="0.9144" y1="-0.3556" x2="0.9144" y2="0.3556" width="0.1524" layer="21"/>
<wire x1="0.9144" y1="1.5748" x2="-0.9144" y2="1.5748" width="0.1524" layer="21"/>
<text x="-2.2098" y="1.3208" size="1.27" layer="21" ratio="6" rot="SR0">*</text>
<text x="-3.2766" y="-0.635" size="1.27" layer="27" ratio="6" rot="SR0">&gt;Name</text>
<text x="-1.7272" y="-0.635" size="1.27" layer="27" ratio="6" rot="SR0">&gt;Value</text>
</package>
<package name="SOT23-5_TS881_TEX-L">
<smd name="1" x="-1.17475" y="0.95" dx="0.7493" dy="0.4572" layer="1"/>
<smd name="2" x="-1.17475" y="0" dx="0.7493" dy="0.4572" layer="1"/>
<smd name="3" x="-1.17475" y="-0.95" dx="0.7493" dy="0.4572" layer="1"/>
<smd name="4" x="1.17475" y="-0.95" dx="0.7493" dy="0.4572" layer="1"/>
<smd name="5" x="1.17475" y="0.95" dx="0.7493" dy="0.4572" layer="1"/>
<wire x1="-0.8128" y1="0.6858" x2="-0.8128" y2="1.1938" width="0.1524" layer="51"/>
<wire x1="-0.8128" y1="1.1938" x2="-1.397" y2="1.1938" width="0.1524" layer="51"/>
<wire x1="-1.397" y1="1.1938" x2="-1.397" y2="0.6858" width="0.1524" layer="51"/>
<wire x1="-1.397" y1="0.6858" x2="-0.8128" y2="0.6858" width="0.1524" layer="51"/>
<wire x1="-0.8128" y1="-0.254" x2="-0.8128" y2="0.254" width="0.1524" layer="51"/>
<wire x1="-0.8128" y1="0.254" x2="-1.397" y2="0.254" width="0.1524" layer="51"/>
<wire x1="-1.397" y1="0.254" x2="-1.397" y2="-0.254" width="0.1524" layer="51"/>
<wire x1="-1.397" y1="-0.254" x2="-0.8128" y2="-0.254" width="0.1524" layer="51"/>
<wire x1="-0.8128" y1="-1.1938" x2="-0.8128" y2="-0.6858" width="0.1524" layer="51"/>
<wire x1="-0.8128" y1="-0.6858" x2="-1.397" y2="-0.6858" width="0.1524" layer="51"/>
<wire x1="-1.397" y1="-0.6858" x2="-1.397" y2="-1.1938" width="0.1524" layer="51"/>
<wire x1="-1.397" y1="-1.1938" x2="-0.8128" y2="-1.1938" width="0.1524" layer="51"/>
<wire x1="0.8128" y1="-0.6858" x2="0.8128" y2="-1.1938" width="0.1524" layer="51"/>
<wire x1="0.8128" y1="-1.1938" x2="1.397" y2="-1.1938" width="0.1524" layer="51"/>
<wire x1="1.397" y1="-1.1938" x2="1.397" y2="-0.6858" width="0.1524" layer="51"/>
<wire x1="1.397" y1="-0.6858" x2="0.8128" y2="-0.6858" width="0.1524" layer="51"/>
<wire x1="0.8128" y1="1.1938" x2="0.8128" y2="0.6858" width="0.1524" layer="51"/>
<wire x1="0.8128" y1="0.6858" x2="1.397" y2="0.6858" width="0.1524" layer="51"/>
<wire x1="1.397" y1="0.6858" x2="1.397" y2="1.1938" width="0.1524" layer="51"/>
<wire x1="1.397" y1="1.1938" x2="0.8128" y2="1.1938" width="0.1524" layer="51"/>
<wire x1="-0.8128" y1="-1.4478" x2="0.8128" y2="-1.4478" width="0.1524" layer="51"/>
<wire x1="0.8128" y1="-1.4478" x2="0.8128" y2="1.4478" width="0.1524" layer="51"/>
<wire x1="0.8128" y1="1.4478" x2="0.3048" y2="1.4478" width="0.1524" layer="51"/>
<wire x1="0.3048" y1="1.4478" x2="-0.3048" y2="1.4478" width="0.1524" layer="51"/>
<wire x1="-0.3048" y1="1.4478" x2="-0.8128" y2="1.4478" width="0.1524" layer="51"/>
<wire x1="-0.8128" y1="1.4478" x2="-0.8128" y2="-1.4478" width="0.1524" layer="51"/>
<wire x1="0.3048" y1="1.4478" x2="-0.3048" y2="1.4478" width="0.1524" layer="51" curve="-180"/>
<text x="-1.1176" y="0.1778" size="1.27" layer="51" ratio="6" rot="SR0">*</text>
<wire x1="-0.8128" y1="3.3528" x2="-0.8128" y2="3.7338" width="0.1524" layer="47"/>
<wire x1="0.8128" y1="0" x2="0.8128" y2="3.3528" width="0.1524" layer="47"/>
<wire x1="0.8128" y1="3.3528" x2="0.8128" y2="3.7338" width="0.1524" layer="47"/>
<wire x1="-0.8128" y1="3.3528" x2="-2.0828" y2="3.3528" width="0.1524" layer="47"/>
<wire x1="0.8128" y1="3.3528" x2="2.0828" y2="3.3528" width="0.1524" layer="47"/>
<wire x1="-0.8128" y1="3.3528" x2="-1.0668" y2="3.4798" width="0.1524" layer="47"/>
<wire x1="-0.8128" y1="3.3528" x2="-1.0668" y2="3.2258" width="0.1524" layer="47"/>
<wire x1="-1.0668" y1="3.4798" x2="-1.0668" y2="3.2258" width="0.1524" layer="47"/>
<wire x1="0.8128" y1="3.3528" x2="1.0668" y2="3.4798" width="0.1524" layer="47"/>
<wire x1="0.8128" y1="3.3528" x2="1.0668" y2="3.2258" width="0.1524" layer="47"/>
<wire x1="1.0668" y1="3.4798" x2="1.0668" y2="3.2258" width="0.1524" layer="47"/>
<wire x1="-1.397" y1="0" x2="-1.397" y2="5.2578" width="0.1524" layer="47"/>
<wire x1="-1.397" y1="5.2578" x2="-1.397" y2="5.6388" width="0.1524" layer="47"/>
<wire x1="1.397" y1="0" x2="1.397" y2="5.2578" width="0.1524" layer="47"/>
<wire x1="1.397" y1="5.2578" x2="1.397" y2="5.6388" width="0.1524" layer="47"/>
<wire x1="-1.397" y1="5.2578" x2="-2.667" y2="5.2578" width="0.1524" layer="47"/>
<wire x1="1.397" y1="5.2578" x2="2.667" y2="5.2578" width="0.1524" layer="47"/>
<wire x1="-1.397" y1="5.2578" x2="-1.651" y2="5.3848" width="0.1524" layer="47"/>
<wire x1="-1.397" y1="5.2578" x2="-1.651" y2="5.1308" width="0.1524" layer="47"/>
<wire x1="-1.651" y1="5.3848" x2="-1.651" y2="5.1308" width="0.1524" layer="47"/>
<wire x1="1.397" y1="5.2578" x2="1.651" y2="5.3848" width="0.1524" layer="47"/>
<wire x1="1.397" y1="5.2578" x2="1.651" y2="5.1308" width="0.1524" layer="47"/>
<wire x1="1.651" y1="5.3848" x2="1.651" y2="5.1308" width="0.1524" layer="47"/>
<wire x1="0" y1="1.4478" x2="8.4328" y2="1.4478" width="0.1524" layer="47"/>
<wire x1="8.4328" y1="1.4478" x2="8.7884" y2="1.4478" width="0.1524" layer="47"/>
<wire x1="0" y1="-1.4478" x2="8.4328" y2="-1.4478" width="0.1524" layer="47"/>
<wire x1="8.4328" y1="-1.4478" x2="8.7884" y2="-1.4478" width="0.1524" layer="47"/>
<wire x1="8.4328" y1="1.4478" x2="8.4328" y2="2.7178" width="0.1524" layer="47"/>
<wire x1="8.4328" y1="-1.4478" x2="8.4328" y2="-2.7178" width="0.1524" layer="47"/>
<wire x1="8.4328" y1="1.4478" x2="8.2804" y2="1.7018" width="0.1524" layer="47"/>
<wire x1="8.4328" y1="1.4478" x2="8.5344" y2="1.7018" width="0.1524" layer="47"/>
<wire x1="8.2804" y1="1.7018" x2="8.5344" y2="1.7018" width="0.1524" layer="47"/>
<wire x1="8.4328" y1="-1.4478" x2="8.2804" y2="-1.7018" width="0.1524" layer="47"/>
<wire x1="8.4328" y1="-1.4478" x2="8.5344" y2="-1.7018" width="0.1524" layer="47"/>
<wire x1="8.2804" y1="-1.7018" x2="8.5344" y2="-1.7018" width="0.1524" layer="47"/>
<wire x1="-1.1684" y1="0.9398" x2="-3.7084" y2="0.9398" width="0.1524" layer="47"/>
<wire x1="-3.7084" y1="0.9398" x2="-4.0894" y2="0.9398" width="0.1524" layer="47"/>
<wire x1="-1.1684" y1="0" x2="-1.397" y2="0" width="0.1524" layer="47"/>
<wire x1="-1.397" y1="0" x2="-3.7084" y2="0" width="0.1524" layer="47"/>
<wire x1="-3.7084" y1="0" x2="-4.0894" y2="0" width="0.1524" layer="47"/>
<wire x1="-3.7084" y1="0.9398" x2="-3.7084" y2="2.2098" width="0.1524" layer="47"/>
<wire x1="-3.7084" y1="0" x2="-3.7084" y2="-1.27" width="0.1524" layer="47"/>
<wire x1="-3.7084" y1="0.9398" x2="-3.8354" y2="1.1938" width="0.1524" layer="47"/>
<wire x1="-3.7084" y1="0.9398" x2="-3.5814" y2="1.1938" width="0.1524" layer="47"/>
<wire x1="-3.8354" y1="1.1938" x2="-3.5814" y2="1.1938" width="0.1524" layer="47"/>
<wire x1="-3.7084" y1="0" x2="-3.8354" y2="-0.254" width="0.1524" layer="47"/>
<wire x1="-3.7084" y1="0" x2="-3.5814" y2="-0.254" width="0.1524" layer="47"/>
<wire x1="-3.8354" y1="-0.254" x2="-3.5814" y2="-0.254" width="0.1524" layer="47"/>
<wire x1="1.1684" y1="0.9398" x2="3.7084" y2="0.9398" width="0.1524" layer="47"/>
<wire x1="3.7084" y1="0.9398" x2="4.0894" y2="0.9398" width="0.1524" layer="47"/>
<wire x1="1.1684" y1="-0.9398" x2="3.7084" y2="-0.9398" width="0.1524" layer="47"/>
<wire x1="3.7084" y1="-0.9398" x2="4.0894" y2="-0.9398" width="0.1524" layer="47"/>
<wire x1="3.7084" y1="0.9398" x2="3.7084" y2="2.2098" width="0.1524" layer="47"/>
<wire x1="3.7084" y1="-0.9398" x2="3.7084" y2="-2.2098" width="0.1524" layer="47"/>
<wire x1="3.7084" y1="0.9398" x2="3.5814" y2="1.1938" width="0.1524" layer="47"/>
<wire x1="3.7084" y1="0.9398" x2="3.8354" y2="1.1938" width="0.1524" layer="47"/>
<wire x1="3.5814" y1="1.1938" x2="3.8354" y2="1.1938" width="0.1524" layer="47"/>
<wire x1="3.7084" y1="-0.9398" x2="3.5814" y2="-1.1938" width="0.1524" layer="47"/>
<wire x1="3.7084" y1="-0.9398" x2="3.8354" y2="-1.1938" width="0.1524" layer="47"/>
<wire x1="3.5814" y1="-1.1938" x2="3.8354" y2="-1.1938" width="0.1524" layer="47"/>
<wire x1="-1.397" y1="0" x2="-1.397" y2="-3.3528" width="0.1524" layer="47"/>
<wire x1="-1.397" y1="-3.3528" x2="-1.397" y2="-3.7338" width="0.1524" layer="47"/>
<wire x1="-0.8128" y1="3.3528" x2="-0.8128" y2="-3.3528" width="0.1524" layer="47"/>
<wire x1="-0.8128" y1="-3.3528" x2="-0.8128" y2="-3.7338" width="0.1524" layer="47"/>
<wire x1="-1.397" y1="-3.3528" x2="-2.667" y2="-3.3528" width="0.1524" layer="47"/>
<wire x1="-0.8128" y1="-3.3528" x2="0.4572" y2="-3.3528" width="0.1524" layer="47"/>
<wire x1="-1.397" y1="-3.3528" x2="-1.651" y2="-3.2258" width="0.1524" layer="47"/>
<wire x1="-1.397" y1="-3.3528" x2="-1.651" y2="-3.4798" width="0.1524" layer="47"/>
<wire x1="-1.651" y1="-3.2258" x2="-1.651" y2="-3.4798" width="0.1524" layer="47"/>
<wire x1="-0.8128" y1="-3.3528" x2="-0.5588" y2="-3.2258" width="0.1524" layer="47"/>
<wire x1="-0.8128" y1="-3.3528" x2="-0.5588" y2="-3.4798" width="0.1524" layer="47"/>
<wire x1="-0.5588" y1="-3.2258" x2="-0.5588" y2="-3.4798" width="0.1524" layer="47"/>
<text x="-16.7386" y="-8.0518" size="1.27" layer="47" ratio="6" rot="SR0">Pin One Padstyle: RX29p5Y18D0T</text>
<text x="-16.3576" y="-6.5278" size="1.27" layer="47" ratio="6" rot="SR0">Default Padstyle: RX29p5Y18D0T</text>
<text x="-14.8082" y="-12.6238" size="1.27" layer="47" ratio="6" rot="SR0">Alt 1 Padstyle: OX60Y90D30P</text>
<text x="-14.8082" y="-14.1478" size="1.27" layer="47" ratio="6" rot="SR0">Alt 2 Padstyle: OX90Y60D30P</text>
<text x="-3.4544" y="3.8608" size="0.635" layer="47" ratio="4" rot="SR0">0.063in/1.6mm</text>
<text x="-3.7592" y="5.7658" size="0.635" layer="47" ratio="4" rot="SR0">0.11in/2.794mm</text>
<text x="8.9408" y="-0.3048" size="0.635" layer="47" ratio="4" rot="SR0">0.114in/2.896mm</text>
<text x="-11.7348" y="0.1524" size="0.635" layer="47" ratio="4" rot="SR0">0.037in/0.95mm</text>
<text x="4.2164" y="-0.3048" size="0.635" layer="47" ratio="4" rot="SR0">0.075in/1.9mm</text>
<text x="-4.8514" y="-4.4958" size="0.635" layer="47" ratio="4" rot="SR0">0.024in/0.61mm</text>
<wire x1="-0.9144" y1="-1.5748" x2="0.9144" y2="-1.5748" width="0.1524" layer="21"/>
<wire x1="0.9144" y1="-0.381" x2="0.9144" y2="0.381" width="0.1524" layer="21"/>
<wire x1="0.9144" y1="1.5748" x2="-0.9144" y2="1.5748" width="0.1524" layer="21"/>
<text x="-2.0066" y="1.27" size="1.27" layer="21" ratio="6" rot="SR0">*</text>
<text x="-3.2766" y="-0.635" size="1.27" layer="27" ratio="6" rot="SR0">&gt;Name</text>
<text x="-1.7272" y="-0.635" size="1.27" layer="27" ratio="6" rot="SR0">&gt;Value</text>
</package>
</packages>
<packages3d>
<package3d name="SOT95P275X130-5N" urn="urn:adsk.eagle:package:40998627/1" type="model">
<description>5-SOT23, 0.95 mm pitch, 2.75 mm span, 2.90 X 1.60 X 1.30 mm body
&lt;p&gt;5-pin SOT23 package with 0.95 mm pitch, 2.75 mm span with body size 2.90 X 1.60 X 1.30 mm&lt;/p&gt;</description>
<packageinstances>
<packageinstance name="SOT95P275X130-5N"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="ADG704BRM">
<pin name="EN" x="2.54" y="0" length="middle" direction="pas"/>
<pin name="A0" x="2.54" y="-5.08" length="middle" direction="pas"/>
<pin name="A1" x="2.54" y="-7.62" length="middle" direction="pas"/>
<pin name="D" x="2.54" y="-12.7" length="middle" direction="pas"/>
<pin name="VDD" x="2.54" y="-17.78" length="middle" direction="pwr"/>
<pin name="S1" x="30.48" y="-12.7" length="middle" direction="pas" rot="R180"/>
<pin name="S2" x="30.48" y="-10.16" length="middle" direction="pas" rot="R180"/>
<pin name="S3" x="30.48" y="-7.62" length="middle" direction="pas" rot="R180"/>
<pin name="S4" x="30.48" y="-5.08" length="middle" direction="pas" rot="R180"/>
<pin name="GND" x="30.48" y="0" length="middle" direction="pas" rot="R180"/>
<wire x1="7.62" y1="2.54" x2="7.62" y2="-20.32" width="0.1524" layer="94"/>
<wire x1="7.62" y1="-20.32" x2="25.4" y2="-20.32" width="0.1524" layer="94"/>
<wire x1="25.4" y1="-20.32" x2="25.4" y2="2.54" width="0.1524" layer="94"/>
<wire x1="25.4" y1="2.54" x2="7.62" y2="2.54" width="0.1524" layer="94"/>
<text x="7.62" y="2.794" size="2.0828" layer="95" ratio="6" rot="SR0">&gt;Name</text>
<text x="7.62" y="-22.86" size="2.0828" layer="96" ratio="6" rot="SR0">&gt;Value</text>
</symbol>
<symbol name="ADG902BRMZ">
<pin name="VDD" x="2.54" y="0" length="middle" direction="pwr"/>
<pin name="CTRL" x="2.54" y="-2.54" length="middle" direction="pas"/>
<pin name="GND_2" x="2.54" y="-5.08" length="middle" direction="pas"/>
<pin name="RF1" x="2.54" y="-7.62" length="middle" direction="pas"/>
<pin name="GND_3" x="33.02" y="-7.62" length="middle" direction="pas" rot="R180"/>
<pin name="GND_4" x="33.02" y="-5.08" length="middle" direction="pas" rot="R180"/>
<pin name="GND" x="33.02" y="-2.54" length="middle" direction="pas" rot="R180"/>
<pin name="RF2" x="33.02" y="0" length="middle" direction="pas" rot="R180"/>
<wire x1="7.62" y1="5.08" x2="7.62" y2="-12.7" width="0.1524" layer="94"/>
<wire x1="7.62" y1="-12.7" x2="27.94" y2="-12.7" width="0.1524" layer="94"/>
<wire x1="27.94" y1="-12.7" x2="27.94" y2="5.08" width="0.1524" layer="94"/>
<wire x1="27.94" y1="5.08" x2="7.62" y2="5.08" width="0.1524" layer="94"/>
<text x="7.62" y="5.334" size="2.0828" layer="95" ratio="6" rot="SR0">&gt;Name</text>
<text x="7.62" y="-15.24" size="2.0828" layer="96" ratio="6" rot="SR0">&gt;Value</text>
</symbol>
<symbol name="BQ25570RGR">
<pin name="VSS_2" x="15.24" y="-20.32" length="middle" direction="pwr" rot="R180"/>
<pin name="VIN_DC" x="-25.4" y="15.24" length="middle" direction="pwr"/>
<pin name="VOC_SAMP" x="15.24" y="22.86" length="middle" direction="in" rot="R180"/>
<pin name="VREF_SAMP" x="-25.4" y="20.32" length="middle" direction="in"/>
<pin name="EN_N" x="-25.4" y="10.16" length="middle" direction="in"/>
<pin name="VOUT_EN" x="-25.4" y="5.08" length="middle" direction="in"/>
<pin name="VBAT_OV" x="-25.4" y="-10.16" length="middle" direction="in"/>
<pin name="VRDIV" x="-25.4" y="-5.08" length="middle" direction="out"/>
<pin name="NC_2" x="15.24" y="-12.7" length="middle" direction="pwr" rot="R180"/>
<pin name="OK_HYST" x="-25.4" y="-20.32" length="middle" direction="in"/>
<pin name="OK_PROG" x="-25.4" y="-15.24" length="middle" direction="in"/>
<pin name="VOUT_SET" x="-25.4" y="-25.4" length="middle" direction="in"/>
<pin name="VBAT_OK" x="-25.4" y="0" length="middle" direction="out"/>
<pin name="VOUT" x="15.24" y="2.54" length="middle" direction="pwr" rot="R180"/>
<pin name="VSS" x="15.24" y="-22.86" length="middle" direction="pwr" rot="R180"/>
<pin name="LBUCK" x="15.24" y="7.62" length="middle" direction="pas" rot="R180"/>
<pin name="NC" x="15.24" y="-15.24" length="middle" direction="pas" rot="R180"/>
<pin name="VBAT" x="15.24" y="12.7" length="middle" rot="R180"/>
<pin name="VSTOR" x="15.24" y="17.78" length="middle" direction="pwr" rot="R180"/>
<pin name="LBOOST" x="-25.4" y="25.4" length="middle" direction="in"/>
<pin name="PAD" x="15.24" y="-25.4" length="middle" direction="pwr" rot="R180"/>
<wire x1="-20.32" y1="-27.94" x2="10.16" y2="-27.94" width="0.1524" layer="94"/>
<wire x1="10.16" y1="-27.94" x2="10.16" y2="27.94" width="0.1524" layer="94"/>
<wire x1="10.16" y1="27.94" x2="-20.32" y2="27.94" width="0.1524" layer="94"/>
<wire x1="-20.32" y1="27.94" x2="-20.32" y2="-27.94" width="0.1524" layer="94"/>
<text x="-20.32" y="28.194" size="2.0828" layer="95" ratio="6" rot="SR0">&gt;Name</text>
<text x="-20.32" y="-30.48" size="2.0828" layer="96" ratio="6" rot="SR0">&gt;Value</text>
</symbol>
<symbol name="S-1313">
<pin name="VIN" x="2.54" y="0" length="middle" direction="pwr"/>
<pin name="GND" x="2.54" y="-2.54" length="middle" direction="pwr"/>
<pin name="ON/OFF" x="2.54" y="-5.08" length="middle" direction="in"/>
<pin name="NC" x="30.48" y="-5.08" length="middle" direction="nc" rot="R180"/>
<pin name="VOUT" x="30.48" y="0" length="middle" direction="pwr" rot="R180"/>
<wire x1="7.62" y1="2.54" x2="25.4" y2="2.54" width="0.254" layer="94"/>
<wire x1="25.4" y1="2.54" x2="25.4" y2="-7.62" width="0.254" layer="94"/>
<wire x1="25.4" y1="-7.62" x2="7.62" y2="-7.62" width="0.254" layer="94"/>
<wire x1="7.62" y1="-7.62" x2="7.62" y2="2.54" width="0.254" layer="94"/>
<text x="7.62" y="2.794" size="1.27" layer="95" ratio="6">&gt;NAME</text>
<text x="7.62" y="-10.16" size="1.27" layer="96" ratio="6">&gt;VALUE</text>
</symbol>
<symbol name="TS881ILT">
<pin name="OUT" x="2.54" y="0" length="middle" direction="out"/>
<pin name="VCC-" x="2.54" y="-2.54" length="middle" direction="pwr"/>
<pin name="IN+" x="30.48" y="-5.08" length="middle" direction="in" rot="R180"/>
<pin name="IN-" x="30.48" y="-2.54" length="middle" direction="in" rot="R180"/>
<pin name="VCC+" x="30.48" y="0" length="middle" direction="pwr" rot="R180"/>
<wire x1="7.62" y1="2.54" x2="7.62" y2="-7.62" width="0.1524" layer="94"/>
<wire x1="7.62" y1="-7.62" x2="25.4" y2="-7.62" width="0.1524" layer="94"/>
<wire x1="25.4" y1="-7.62" x2="25.4" y2="2.54" width="0.1524" layer="94"/>
<wire x1="25.4" y1="2.54" x2="7.62" y2="2.54" width="0.1524" layer="94"/>
<text x="7.62" y="2.794" size="2.0828" layer="95" ratio="6" rot="SR0">&gt;Name</text>
<text x="7.62" y="-10.16" size="2.0828" layer="96" ratio="6" rot="SR0">&gt;Value</text>
</symbol>
<symbol name="ADG723BRMZ_SWITCH">
<pin name="S1" x="2.54" y="-10.16" length="middle" direction="pas"/>
<pin name="D1" x="43.18" y="-10.16" length="middle" direction="pas" rot="R180"/>
<pin name="IN2" x="2.54" y="-12.7" length="middle" direction="pas"/>
<pin name="GND" x="2.54" y="-22.86" length="middle" direction="pas"/>
<pin name="S2" x="2.54" y="-17.78" length="middle" direction="pas"/>
<pin name="D2" x="43.18" y="-17.78" length="middle" direction="pas" rot="R180"/>
<pin name="IN1" x="2.54" y="-5.08" length="middle" direction="pas"/>
<pin name="VDD" x="2.54" y="0" length="middle" direction="pwr"/>
<wire x1="7.62" y1="2.54" x2="7.62" y2="-25.4" width="0.1524" layer="94"/>
<wire x1="7.62" y1="-25.4" x2="38.1" y2="-25.4" width="0.1524" layer="94"/>
<wire x1="38.1" y1="-25.4" x2="38.1" y2="2.54" width="0.1524" layer="94"/>
<wire x1="38.1" y1="2.54" x2="7.62" y2="2.54" width="0.1524" layer="94"/>
<text x="7.62" y="2.794" size="2.0828" layer="95" ratio="6" rot="SR0">&gt;Name</text>
<text x="7.62" y="-27.94" size="2.0828" layer="96" ratio="6" rot="SR0">&gt;Value</text>
<wire x1="15.24" y1="-17.78" x2="17.78" y2="-17.78" width="0.254" layer="94"/>
<wire x1="17.78" y1="-17.78" x2="25.4" y2="-16.002" width="0.254" layer="94"/>
<wire x1="22.86" y1="-16.51" x2="22.86" y2="-12.7" width="0.254" layer="94" style="shortdash"/>
<wire x1="22.86" y1="-12.7" x2="15.24" y2="-12.7" width="0.254" layer="94" style="shortdash"/>
<polygon width="0.254" layer="94">
<vertex x="22.86" y="-17.78"/>
<vertex x="24.13" y="-16.51"/>
<vertex x="25.4" y="-17.78"/>
</polygon>
<wire x1="25.4" y1="-17.78" x2="30.48" y2="-17.78" width="0.254" layer="94"/>
<wire x1="15.24" y1="-10.16" x2="17.78" y2="-10.16" width="0.254" layer="94"/>
<wire x1="17.78" y1="-10.16" x2="22.86" y2="-7.62" width="0.254" layer="94"/>
<wire x1="22.86" y1="-7.62" x2="25.4" y2="-6.35" width="0.254" layer="94"/>
<wire x1="22.86" y1="-7.62" x2="22.86" y2="-5.08" width="0.254" layer="94" style="shortdash"/>
<wire x1="22.86" y1="-5.08" x2="15.24" y2="-5.08" width="0.254" layer="94" style="shortdash"/>
<polygon width="0.254" layer="94">
<vertex x="22.86" y="-10.16"/>
<vertex x="24.13" y="-8.89"/>
<vertex x="25.4" y="-10.16"/>
</polygon>
<wire x1="25.4" y1="-10.16" x2="30.48" y2="-10.16" width="0.254" layer="94"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="ADG704BRMZ" prefix="U">
<description>IC SWITCH SP4T X 1 4OHM 10MSOP</description>
<gates>
<gate name="A" symbol="ADG704BRM" x="0" y="0" swaplevel="1"/>
</gates>
<devices>
<device name="" package="RM_10_ADI">
<connects>
<connect gate="A" pin="A0" pad="1"/>
<connect gate="A" pin="A1" pad="10"/>
<connect gate="A" pin="D" pad="8"/>
<connect gate="A" pin="EN" pad="5"/>
<connect gate="A" pin="GND" pad="3"/>
<connect gate="A" pin="S1" pad="2"/>
<connect gate="A" pin="S2" pad="9"/>
<connect gate="A" pin="S3" pad="4"/>
<connect gate="A" pin="S4" pad="7"/>
<connect gate="A" pin="VDD" pad="6"/>
</connects>
<technologies>
<technology name="">
<attribute name="COPYRIGHT" value="Copyright (C) 2023 Ultra Librarian. All rights reserved." constant="no"/>
<attribute name="DIGIKEY_PART_NUMBER_1" value="ADG704BRMZ-ND" constant="no"/>
<attribute name="MANUFACTURER_PART_NUMBER" value="ADG704BRMZ" constant="no"/>
<attribute name="MFR_NAME" value="Analog Devices Inc" constant="no"/>
</technology>
</technologies>
</device>
<device name="RM_10_ADI-M" package="RM_10_ADI-M">
<connects>
<connect gate="A" pin="A0" pad="1"/>
<connect gate="A" pin="A1" pad="10"/>
<connect gate="A" pin="D" pad="8"/>
<connect gate="A" pin="EN" pad="5"/>
<connect gate="A" pin="GND" pad="3"/>
<connect gate="A" pin="S1" pad="2"/>
<connect gate="A" pin="S2" pad="9"/>
<connect gate="A" pin="S3" pad="4"/>
<connect gate="A" pin="S4" pad="7"/>
<connect gate="A" pin="VDD" pad="6"/>
</connects>
<technologies>
<technology name="">
<attribute name="COPYRIGHT" value="Copyright (C) 2023 Ultra Librarian. All rights reserved." constant="no"/>
<attribute name="DIGIKEY_PART_NUMBER_1" value="ADG704BRMZ-ND" constant="no"/>
<attribute name="MANUFACTURER_PART_NUMBER" value="ADG704BRMZ" constant="no"/>
<attribute name="MFR_NAME" value="Analog Devices Inc" constant="no"/>
</technology>
</technologies>
</device>
<device name="RM_10_ADI-L" package="RM_10_ADI-L">
<connects>
<connect gate="A" pin="A0" pad="1"/>
<connect gate="A" pin="A1" pad="10"/>
<connect gate="A" pin="D" pad="8"/>
<connect gate="A" pin="EN" pad="5"/>
<connect gate="A" pin="GND" pad="3"/>
<connect gate="A" pin="S1" pad="2"/>
<connect gate="A" pin="S2" pad="9"/>
<connect gate="A" pin="S3" pad="4"/>
<connect gate="A" pin="S4" pad="7"/>
<connect gate="A" pin="VDD" pad="6"/>
</connects>
<technologies>
<technology name="">
<attribute name="COPYRIGHT" value="Copyright (C) 2023 Ultra Librarian. All rights reserved." constant="no"/>
<attribute name="DIGIKEY_PART_NUMBER_1" value="ADG704BRMZ-ND" constant="no"/>
<attribute name="MANUFACTURER_PART_NUMBER" value="ADG704BRMZ" constant="no"/>
<attribute name="MFR_NAME" value="Analog Devices Inc" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="ADG902BRMZ" prefix="U">
<description>IC RF SWITCH SPST 2.5GHZ 8MSOP</description>
<gates>
<gate name="A" symbol="ADG902BRMZ" x="0" y="0"/>
</gates>
<devices>
<device name="" package="RM_8_ADI">
<connects>
<connect gate="A" pin="CTRL" pad="2"/>
<connect gate="A" pin="GND" pad="7"/>
<connect gate="A" pin="GND_2" pad="3"/>
<connect gate="A" pin="GND_3" pad="5"/>
<connect gate="A" pin="GND_4" pad="6"/>
<connect gate="A" pin="RF1" pad="4"/>
<connect gate="A" pin="RF2" pad="8"/>
<connect gate="A" pin="VDD" pad="1"/>
</connects>
<technologies>
<technology name="">
<attribute name="COPYRIGHT" value="Copyright (C) 2023 Ultra Librarian. All rights reserved." constant="no"/>
<attribute name="DIGIKEY_PART_NUMBER_1" value="ADG902BRMZ-ND" constant="no"/>
<attribute name="DIGIKEY_PART_NUMBER_2" value="2156-ADG902BRMZ-ND" constant="no"/>
<attribute name="MANUFACTURER_PART_NUMBER" value="ADG902BRMZ" constant="no"/>
<attribute name="MFR_NAME" value="Analog Devices Inc" constant="no"/>
</technology>
</technologies>
</device>
<device name="RM_8_ADI-M" package="RM_8_ADI-M">
<connects>
<connect gate="A" pin="CTRL" pad="2"/>
<connect gate="A" pin="GND" pad="7"/>
<connect gate="A" pin="GND_2" pad="3"/>
<connect gate="A" pin="GND_3" pad="5"/>
<connect gate="A" pin="GND_4" pad="6"/>
<connect gate="A" pin="RF1" pad="4"/>
<connect gate="A" pin="RF2" pad="8"/>
<connect gate="A" pin="VDD" pad="1"/>
</connects>
<technologies>
<technology name="">
<attribute name="COPYRIGHT" value="Copyright (C) 2023 Ultra Librarian. All rights reserved." constant="no"/>
<attribute name="DIGIKEY_PART_NUMBER_1" value="ADG902BRMZ-ND" constant="no"/>
<attribute name="DIGIKEY_PART_NUMBER_2" value="2156-ADG902BRMZ-ND" constant="no"/>
<attribute name="MANUFACTURER_PART_NUMBER" value="ADG902BRMZ" constant="no"/>
<attribute name="MFR_NAME" value="Analog Devices Inc" constant="no"/>
</technology>
</technologies>
</device>
<device name="RM_8_ADI-L" package="RM_8_ADI-L">
<connects>
<connect gate="A" pin="CTRL" pad="2"/>
<connect gate="A" pin="GND" pad="7"/>
<connect gate="A" pin="GND_2" pad="3"/>
<connect gate="A" pin="GND_3" pad="5"/>
<connect gate="A" pin="GND_4" pad="6"/>
<connect gate="A" pin="RF1" pad="4"/>
<connect gate="A" pin="RF2" pad="8"/>
<connect gate="A" pin="VDD" pad="1"/>
</connects>
<technologies>
<technology name="">
<attribute name="COPYRIGHT" value="Copyright (C) 2023 Ultra Librarian. All rights reserved." constant="no"/>
<attribute name="DIGIKEY_PART_NUMBER_1" value="ADG902BRMZ-ND" constant="no"/>
<attribute name="DIGIKEY_PART_NUMBER_2" value="2156-ADG902BRMZ-ND" constant="no"/>
<attribute name="MANUFACTURER_PART_NUMBER" value="ADG902BRMZ" constant="no"/>
<attribute name="MFR_NAME" value="Analog Devices Inc" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="BQ25570RGRR" prefix="U">
<description>IC ENERGY HARV CTRLR BATT 20VQFN</description>
<gates>
<gate name="A" symbol="BQ25570RGR" x="0" y="0"/>
</gates>
<devices>
<device name="" package="RGR0020A">
<connects>
<connect gate="A" pin="EN_N" pad="5"/>
<connect gate="A" pin="LBOOST" pad="20"/>
<connect gate="A" pin="LBUCK" pad="16"/>
<connect gate="A" pin="NC" pad="17"/>
<connect gate="A" pin="NC_2" pad="9"/>
<connect gate="A" pin="OK_HYST" pad="10"/>
<connect gate="A" pin="OK_PROG" pad="11"/>
<connect gate="A" pin="PAD" pad="21"/>
<connect gate="A" pin="VBAT" pad="18"/>
<connect gate="A" pin="VBAT_OK" pad="13"/>
<connect gate="A" pin="VBAT_OV" pad="7"/>
<connect gate="A" pin="VIN_DC" pad="2"/>
<connect gate="A" pin="VOC_SAMP" pad="3"/>
<connect gate="A" pin="VOUT" pad="14"/>
<connect gate="A" pin="VOUT_EN" pad="6"/>
<connect gate="A" pin="VOUT_SET" pad="12"/>
<connect gate="A" pin="VRDIV" pad="8"/>
<connect gate="A" pin="VREF_SAMP" pad="4"/>
<connect gate="A" pin="VSS" pad="15"/>
<connect gate="A" pin="VSS_2" pad="1"/>
<connect gate="A" pin="VSTOR" pad="19"/>
</connects>
<technologies>
<technology name="">
<attribute name="COPYRIGHT" value="Copyright (C) 2023 Ultra Librarian. All rights reserved." constant="no"/>
<attribute name="DIGIKEY_PART_NUMBER_1" value="2156-BQ25570RGRR-ND" constant="no"/>
<attribute name="DIGIKEY_PART_NUMBER_2" value="296-39934-1-ND" constant="no"/>
<attribute name="DIGIKEY_PART_NUMBER_3" value="296-39934-2-ND" constant="no"/>
<attribute name="DIGIKEY_PART_NUMBER_4" value="296-39934-6-ND" constant="no"/>
<attribute name="DIGIKEY_PART_NUMBER_5" value="BQ25570RGRR-ND" constant="no"/>
<attribute name="MANUFACTURER_PART_NUMBER" value="BQ25570RGRR" constant="no"/>
<attribute name="MFR_NAME" value="Texas Instruments" constant="no"/>
<attribute name="REFDES" value="RefDes" constant="no"/>
<attribute name="TYPE" value="TYPE" constant="no"/>
</technology>
</technologies>
</device>
<device name="RGR0020A_NV" package="RGR0020A_NV">
<connects>
<connect gate="A" pin="EN_N" pad="5"/>
<connect gate="A" pin="LBOOST" pad="20"/>
<connect gate="A" pin="LBUCK" pad="16"/>
<connect gate="A" pin="NC" pad="17"/>
<connect gate="A" pin="NC_2" pad="9"/>
<connect gate="A" pin="OK_HYST" pad="10"/>
<connect gate="A" pin="OK_PROG" pad="11"/>
<connect gate="A" pin="PAD" pad="21"/>
<connect gate="A" pin="VBAT" pad="18"/>
<connect gate="A" pin="VBAT_OK" pad="13"/>
<connect gate="A" pin="VBAT_OV" pad="7"/>
<connect gate="A" pin="VIN_DC" pad="2"/>
<connect gate="A" pin="VOC_SAMP" pad="3"/>
<connect gate="A" pin="VOUT" pad="14"/>
<connect gate="A" pin="VOUT_EN" pad="6"/>
<connect gate="A" pin="VOUT_SET" pad="12"/>
<connect gate="A" pin="VRDIV" pad="8"/>
<connect gate="A" pin="VREF_SAMP" pad="4"/>
<connect gate="A" pin="VSS" pad="15"/>
<connect gate="A" pin="VSS_2" pad="1"/>
<connect gate="A" pin="VSTOR" pad="19"/>
</connects>
<technologies>
<technology name="">
<attribute name="COPYRIGHT" value="Copyright (C) 2023 Ultra Librarian. All rights reserved." constant="no"/>
<attribute name="DIGIKEY_PART_NUMBER_1" value="2156-BQ25570RGRR-ND" constant="no"/>
<attribute name="DIGIKEY_PART_NUMBER_2" value="296-39934-1-ND" constant="no"/>
<attribute name="DIGIKEY_PART_NUMBER_3" value="296-39934-2-ND" constant="no"/>
<attribute name="DIGIKEY_PART_NUMBER_4" value="296-39934-6-ND" constant="no"/>
<attribute name="DIGIKEY_PART_NUMBER_5" value="BQ25570RGRR-ND" constant="no"/>
<attribute name="MANUFACTURER_PART_NUMBER" value="BQ25570RGRR" constant="no"/>
<attribute name="MFR_NAME" value="Texas Instruments" constant="no"/>
<attribute name="REFDES" value="RefDes" constant="no"/>
<attribute name="TYPE" value="TYPE" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="S-1313B24-M5T1U3">
<description>IC REG LINEAR 2.4V 200MA SOT23-5</description>
<gates>
<gate name="A" symbol="S-1313" x="0" y="0"/>
</gates>
<devices>
<device name="SOT-23-5" package="SOT95P275X130-5N">
<connects>
<connect gate="A" pin="GND" pad="2"/>
<connect gate="A" pin="NC" pad="4"/>
<connect gate="A" pin="ON/OFF" pad="3"/>
<connect gate="A" pin="VIN" pad="1"/>
<connect gate="A" pin="VOUT" pad="5"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:40998627/1"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="TS881ILT" prefix="U">
<description>IC COMPARATOR 1 GEN PUR SOT23-5</description>
<gates>
<gate name="A" symbol="TS881ILT" x="0" y="0"/>
</gates>
<devices>
<device name="" package="SOT23-5_TS881_TEX">
<connects>
<connect gate="A" pin="IN+" pad="3"/>
<connect gate="A" pin="IN-" pad="4"/>
<connect gate="A" pin="OUT" pad="1"/>
<connect gate="A" pin="VCC+" pad="5"/>
<connect gate="A" pin="VCC-" pad="2"/>
</connects>
<technologies>
<technology name="">
<attribute name="COPYRIGHT" value="Copyright (C) 2023 Ultra Librarian. All rights reserved." constant="no"/>
<attribute name="DIGIKEY_PART_NUMBER_1" value="497-14339-2-ND" constant="no"/>
<attribute name="DIGIKEY_PART_NUMBER_2" value="497-14339-1-ND" constant="no"/>
<attribute name="DIGIKEY_PART_NUMBER_3" value="497-14339-6-ND" constant="no"/>
<attribute name="MANUFACTURER_PART_NUMBER" value="TS881ILT" constant="no"/>
<attribute name="MFR_NAME" value="STMicroelectronics" constant="no"/>
</technology>
</technologies>
</device>
<device name="SOT23-5_TS881_TEX-M" package="SOT23-5_TS881_TEX-M">
<connects>
<connect gate="A" pin="IN+" pad="3"/>
<connect gate="A" pin="IN-" pad="4"/>
<connect gate="A" pin="OUT" pad="1"/>
<connect gate="A" pin="VCC+" pad="5"/>
<connect gate="A" pin="VCC-" pad="2"/>
</connects>
<technologies>
<technology name="">
<attribute name="COPYRIGHT" value="Copyright (C) 2023 Ultra Librarian. All rights reserved." constant="no"/>
<attribute name="DIGIKEY_PART_NUMBER_1" value="497-14339-2-ND" constant="no"/>
<attribute name="DIGIKEY_PART_NUMBER_2" value="497-14339-1-ND" constant="no"/>
<attribute name="DIGIKEY_PART_NUMBER_3" value="497-14339-6-ND" constant="no"/>
<attribute name="MANUFACTURER_PART_NUMBER" value="TS881ILT" constant="no"/>
<attribute name="MFR_NAME" value="STMicroelectronics" constant="no"/>
</technology>
</technologies>
</device>
<device name="SOT23-5_TS881_TEX-L" package="SOT23-5_TS881_TEX-L">
<connects>
<connect gate="A" pin="IN+" pad="3"/>
<connect gate="A" pin="IN-" pad="4"/>
<connect gate="A" pin="OUT" pad="1"/>
<connect gate="A" pin="VCC+" pad="5"/>
<connect gate="A" pin="VCC-" pad="2"/>
</connects>
<technologies>
<technology name="">
<attribute name="COPYRIGHT" value="Copyright (C) 2023 Ultra Librarian. All rights reserved." constant="no"/>
<attribute name="DIGIKEY_PART_NUMBER_1" value="497-14339-2-ND" constant="no"/>
<attribute name="DIGIKEY_PART_NUMBER_2" value="497-14339-1-ND" constant="no"/>
<attribute name="DIGIKEY_PART_NUMBER_3" value="497-14339-6-ND" constant="no"/>
<attribute name="MANUFACTURER_PART_NUMBER" value="TS881ILT" constant="no"/>
<attribute name="MFR_NAME" value="STMicroelectronics" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="ADG723BRMZ" prefix="U">
<description>IC SW SPST-NO/NCX2 4OHM 8MSOP</description>
<gates>
<gate name="A" symbol="ADG723BRMZ_SWITCH" x="0" y="0"/>
</gates>
<devices>
<device name="" package="RM_8_ADI">
<connects>
<connect gate="A" pin="D1" pad="2"/>
<connect gate="A" pin="D2" pad="6"/>
<connect gate="A" pin="GND" pad="4"/>
<connect gate="A" pin="IN1" pad="7"/>
<connect gate="A" pin="IN2" pad="3"/>
<connect gate="A" pin="S1" pad="1"/>
<connect gate="A" pin="S2" pad="5"/>
<connect gate="A" pin="VDD" pad="8"/>
</connects>
<technologies>
<technology name="">
<attribute name="COPYRIGHT" value="Copyright (C) 2023 Ultra Librarian. All rights reserved." constant="no"/>
<attribute name="DIGIKEY_PART_NUMBER_1" value="ADG723BRMZ-ND" constant="no"/>
<attribute name="DIGIKEY_PART_NUMBER_2" value="2156-ADG723BRMZ-ND" constant="no"/>
<attribute name="MANUFACTURER_PART_NUMBER" value="ADG723BRMZ" constant="no"/>
<attribute name="MFR_NAME" value="Analog Devices Inc" constant="no"/>
</technology>
</technologies>
</device>
<device name="RM_8_ADI-M" package="RM_8_ADI-M">
<connects>
<connect gate="A" pin="D1" pad="2"/>
<connect gate="A" pin="D2" pad="6"/>
<connect gate="A" pin="GND" pad="4"/>
<connect gate="A" pin="IN1" pad="7"/>
<connect gate="A" pin="IN2" pad="3"/>
<connect gate="A" pin="S1" pad="1"/>
<connect gate="A" pin="S2" pad="5"/>
<connect gate="A" pin="VDD" pad="8"/>
</connects>
<technologies>
<technology name="">
<attribute name="COPYRIGHT" value="Copyright (C) 2023 Ultra Librarian. All rights reserved." constant="no"/>
<attribute name="DIGIKEY_PART_NUMBER_1" value="ADG723BRMZ-ND" constant="no"/>
<attribute name="DIGIKEY_PART_NUMBER_2" value="2156-ADG723BRMZ-ND" constant="no"/>
<attribute name="MANUFACTURER_PART_NUMBER" value="ADG723BRMZ" constant="no"/>
<attribute name="MFR_NAME" value="Analog Devices Inc" constant="no"/>
</technology>
</technologies>
</device>
<device name="RM_8_ADI-L" package="RM_8_ADI-L">
<connects>
<connect gate="A" pin="D1" pad="2"/>
<connect gate="A" pin="D2" pad="6"/>
<connect gate="A" pin="GND" pad="4"/>
<connect gate="A" pin="IN1" pad="7"/>
<connect gate="A" pin="IN2" pad="3"/>
<connect gate="A" pin="S1" pad="1"/>
<connect gate="A" pin="S2" pad="5"/>
<connect gate="A" pin="VDD" pad="8"/>
</connects>
<technologies>
<technology name="">
<attribute name="COPYRIGHT" value="Copyright (C) 2023 Ultra Librarian. All rights reserved." constant="no"/>
<attribute name="DIGIKEY_PART_NUMBER_1" value="ADG723BRMZ-ND" constant="no"/>
<attribute name="DIGIKEY_PART_NUMBER_2" value="2156-ADG723BRMZ-ND" constant="no"/>
<attribute name="MANUFACTURER_PART_NUMBER" value="ADG723BRMZ" constant="no"/>
<attribute name="MFR_NAME" value="Analog Devices Inc" constant="no"/>
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
<modules>
<module name="TEST" prefix="" dx="30.48" dy="20.32">
<ports>
</ports>
<variantdefs>
</variantdefs>
<parts>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
</instances>
<busses>
</busses>
<nets>
</nets>
</sheet>
</sheets>
</module>
</modules>
<parts>
<part name="FRAME1" library="frames" library_urn="urn:adsk.eagle:library:229" deviceset="FRAME_A_L" device=""/>
<part name="U1" library="PassiveLiFiTag" deviceset="ADG704BRMZ" device=""/>
<part name="U10" library="PassiveLiFiTag" deviceset="ADG902BRMZ" device=""/>
<part name="U11" library="PassiveLiFiTag" deviceset="BQ25570RGRR" device=""/>
<part name="U$1" library="PassiveLiFiTag" deviceset="S-1313B24-M5T1U3" device="SOT-23-5" package3d_urn="urn:adsk.eagle:package:40998627/1"/>
<part name="U12" library="PassiveLiFiTag" deviceset="TS881ILT" device=""/>
<part name="U2" library="PassiveLiFiTag" deviceset="ADG723BRMZ" device=""/>
<part name="U3" library="PassiveLiFiTag" deviceset="ADG723BRMZ" device=""/>
<part name="U4" library="PassiveLiFiTag" deviceset="ADG723BRMZ" device=""/>
<part name="U5" library="PassiveLiFiTag" deviceset="ADG723BRMZ" device=""/>
<part name="U6" library="PassiveLiFiTag" deviceset="ADG723BRMZ" device=""/>
<part name="U7" library="PassiveLiFiTag" deviceset="ADG723BRMZ" device=""/>
<part name="U8" library="PassiveLiFiTag" deviceset="ADG723BRMZ" device=""/>
<part name="U9" library="PassiveLiFiTag" deviceset="ADG723BRMZ" device=""/>
</parts>
<sheets>
<sheet>
<plain>
<text x="86.36" y="60.96" size="1.778" layer="97">2.4 V Linear Regulator</text>
<text x="101.6" y="25.4" size="1.778" layer="97">Comparator</text>
<text x="27.94" y="66.04" size="1.778" layer="97">Battery Management</text>
<text x="127" y="205.74" size="1.778" layer="97">Battery Parallel/Series Switches</text>
<text x="246.38" y="104.14" size="1.778" layer="97">RF Mux</text>
<text x="246.38" y="68.58" size="1.778" layer="97">RF Switch</text>
</plain>
<instances>
<instance part="FRAME1" gate="G$1" x="0" y="0" smashed="yes"/>
<instance part="FRAME1" gate="G$2" x="172.72" y="0" smashed="yes">
<attribute name="LAST_DATE_TIME" x="185.42" y="1.27" size="2.54" layer="94"/>
<attribute name="SHEET" x="259.08" y="1.27" size="2.54" layer="94"/>
<attribute name="DRAWING_NAME" x="190.5" y="19.05" size="2.54" layer="94"/>
</instance>
<instance part="U1" gate="A" x="238.76" y="99.06" smashed="yes">
<attribute name="NAME" x="246.38" y="101.854" size="2.0828" layer="95" ratio="6" rot="SR0"/>
<attribute name="VALUE" x="246.38" y="76.2" size="2.0828" layer="96" ratio="6" rot="SR0"/>
</instance>
<instance part="U10" gate="A" x="238.76" y="60.96" smashed="yes">
<attribute name="NAME" x="246.38" y="66.294" size="2.0828" layer="95" ratio="6" rot="SR0"/>
<attribute name="VALUE" x="246.38" y="45.72" size="2.0828" layer="96" ratio="6" rot="SR0"/>
</instance>
<instance part="U11" gate="A" x="48.26" y="33.02" smashed="yes">
<attribute name="NAME" x="27.94" y="61.214" size="2.0828" layer="95" ratio="6" rot="SR0"/>
<attribute name="VALUE" x="27.94" y="2.54" size="2.0828" layer="96" ratio="6" rot="SR0"/>
</instance>
<instance part="U$1" gate="A" x="83.82" y="55.88" smashed="yes">
<attribute name="NAME" x="91.44" y="58.674" size="1.27" layer="95" ratio="6"/>
<attribute name="VALUE" x="91.44" y="45.72" size="1.27" layer="96" ratio="6"/>
</instance>
<instance part="U12" gate="A" x="99.06" y="17.78" smashed="yes">
<attribute name="NAME" x="106.68" y="20.574" size="2.0828" layer="95" ratio="6" rot="SR0"/>
<attribute name="VALUE" x="106.68" y="7.62" size="2.0828" layer="96" ratio="6" rot="SR0"/>
</instance>
<instance part="U2" gate="A" x="20.32" y="205.74" smashed="yes">
<attribute name="NAME" x="27.94" y="208.534" size="2.0828" layer="95" ratio="6" rot="SR0"/>
<attribute name="VALUE" x="27.94" y="177.8" size="2.0828" layer="96" ratio="6" rot="SR0"/>
</instance>
<instance part="U3" gate="A" x="78.74" y="205.74" smashed="yes">
<attribute name="NAME" x="86.36" y="208.534" size="2.0828" layer="95" ratio="6" rot="SR0"/>
<attribute name="VALUE" x="86.36" y="177.8" size="2.0828" layer="96" ratio="6" rot="SR0"/>
</instance>
<instance part="U4" gate="A" x="20.32" y="170.18" smashed="yes">
<attribute name="NAME" x="27.94" y="172.974" size="2.0828" layer="95" ratio="6" rot="SR0"/>
<attribute name="VALUE" x="27.94" y="142.24" size="2.0828" layer="96" ratio="6" rot="SR0"/>
</instance>
<instance part="U5" gate="A" x="78.74" y="170.18" smashed="yes">
<attribute name="NAME" x="86.36" y="172.974" size="2.0828" layer="95" ratio="6" rot="SR0"/>
<attribute name="VALUE" x="86.36" y="142.24" size="2.0828" layer="96" ratio="6" rot="SR0"/>
</instance>
<instance part="U6" gate="A" x="20.32" y="134.62" smashed="yes">
<attribute name="NAME" x="27.94" y="137.414" size="2.0828" layer="95" ratio="6" rot="SR0"/>
<attribute name="VALUE" x="27.94" y="106.68" size="2.0828" layer="96" ratio="6" rot="SR0"/>
</instance>
<instance part="U7" gate="A" x="78.74" y="134.62" smashed="yes">
<attribute name="NAME" x="86.36" y="137.414" size="2.0828" layer="95" ratio="6" rot="SR0"/>
<attribute name="VALUE" x="86.36" y="106.68" size="2.0828" layer="96" ratio="6" rot="SR0"/>
</instance>
<instance part="U8" gate="A" x="20.32" y="99.06" smashed="yes">
<attribute name="NAME" x="27.94" y="101.854" size="2.0828" layer="95" ratio="6" rot="SR0"/>
<attribute name="VALUE" x="27.94" y="71.12" size="2.0828" layer="96" ratio="6" rot="SR0"/>
</instance>
<instance part="U9" gate="A" x="78.74" y="99.06" smashed="yes">
<attribute name="NAME" x="86.36" y="101.854" size="2.0828" layer="95" ratio="6" rot="SR0"/>
<attribute name="VALUE" x="86.36" y="71.12" size="2.0828" layer="96" ratio="6" rot="SR0"/>
</instance>
</instances>
<busses>
</busses>
<nets>
<net name="VDD2.4" class="0">
<segment>
<pinref part="U2" gate="A" pin="VDD"/>
<wire x1="22.86" y1="205.74" x2="17.78" y2="205.74" width="0.1524" layer="91"/>
<label x="12.7" y="205.74" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U4" gate="A" pin="VDD"/>
<wire x1="22.86" y1="170.18" x2="17.78" y2="170.18" width="0.1524" layer="91"/>
<label x="12.7" y="170.18" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U3" gate="A" pin="VDD"/>
<wire x1="81.28" y1="205.74" x2="76.2" y2="205.74" width="0.1524" layer="91"/>
<label x="71.12" y="205.74" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U5" gate="A" pin="VDD"/>
<wire x1="81.28" y1="170.18" x2="76.2" y2="170.18" width="0.1524" layer="91"/>
<label x="71.12" y="170.18" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U6" gate="A" pin="VDD"/>
<wire x1="22.86" y1="134.62" x2="17.78" y2="134.62" width="0.1524" layer="91"/>
<label x="12.7" y="134.62" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U7" gate="A" pin="VDD"/>
<wire x1="81.28" y1="134.62" x2="76.2" y2="134.62" width="0.1524" layer="91"/>
<label x="71.12" y="134.62" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U8" gate="A" pin="VDD"/>
<wire x1="22.86" y1="99.06" x2="17.78" y2="99.06" width="0.1524" layer="91"/>
<label x="12.7" y="99.06" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U9" gate="A" pin="VDD"/>
<wire x1="81.28" y1="99.06" x2="76.2" y2="99.06" width="0.1524" layer="91"/>
<label x="71.12" y="99.06" size="1.778" layer="95"/>
</segment>
</net>
<net name="GND" class="0">
<segment>
<pinref part="U2" gate="A" pin="GND"/>
<wire x1="22.86" y1="182.88" x2="17.78" y2="182.88" width="0.1524" layer="91"/>
<label x="12.7" y="182.88" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U3" gate="A" pin="GND"/>
<wire x1="81.28" y1="182.88" x2="76.2" y2="182.88" width="0.1524" layer="91"/>
<label x="71.12" y="182.88" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U4" gate="A" pin="GND"/>
<wire x1="22.86" y1="147.32" x2="17.78" y2="147.32" width="0.1524" layer="91"/>
<label x="12.7" y="147.32" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U5" gate="A" pin="GND"/>
<wire x1="81.28" y1="147.32" x2="76.2" y2="147.32" width="0.1524" layer="91"/>
<label x="71.12" y="147.32" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U6" gate="A" pin="GND"/>
<wire x1="22.86" y1="111.76" x2="17.78" y2="111.76" width="0.1524" layer="91"/>
<label x="12.7" y="111.76" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U7" gate="A" pin="GND"/>
<wire x1="81.28" y1="111.76" x2="76.2" y2="111.76" width="0.1524" layer="91"/>
<label x="71.12" y="111.76" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U8" gate="A" pin="GND"/>
<wire x1="22.86" y1="76.2" x2="17.78" y2="76.2" width="0.1524" layer="91"/>
<label x="12.7" y="76.2" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U9" gate="A" pin="GND"/>
<wire x1="81.28" y1="76.2" x2="76.2" y2="76.2" width="0.1524" layer="91"/>
<label x="71.12" y="76.2" size="1.778" layer="95"/>
</segment>
</net>
<net name="BATTERY_OK" class="0">
<segment>
<pinref part="U2" gate="A" pin="IN1"/>
<wire x1="22.86" y1="200.66" x2="17.78" y2="200.66" width="0.1524" layer="91"/>
<label x="5.08" y="200.66" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U2" gate="A" pin="IN2"/>
<wire x1="22.86" y1="193.04" x2="17.78" y2="193.04" width="0.1524" layer="91"/>
<label x="5.08" y="193.04" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U3" gate="A" pin="IN1"/>
<wire x1="81.28" y1="200.66" x2="76.2" y2="200.66" width="0.1524" layer="91"/>
<label x="63.5" y="200.66" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U3" gate="A" pin="IN2"/>
<wire x1="81.28" y1="193.04" x2="76.2" y2="193.04" width="0.1524" layer="91"/>
<label x="63.5" y="193.04" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U8" gate="A" pin="IN1"/>
<wire x1="22.86" y1="93.98" x2="17.78" y2="93.98" width="0.1524" layer="91"/>
<label x="5.08" y="93.98" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U8" gate="A" pin="IN2"/>
<wire x1="22.86" y1="86.36" x2="17.78" y2="86.36" width="0.1524" layer="91"/>
<label x="5.08" y="86.36" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U9" gate="A" pin="IN2"/>
<wire x1="81.28" y1="86.36" x2="76.2" y2="86.36" width="0.1524" layer="91"/>
<label x="63.5" y="86.36" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U9" gate="A" pin="IN1"/>
<wire x1="81.28" y1="93.98" x2="76.2" y2="93.98" width="0.1524" layer="91"/>
<label x="63.5" y="93.98" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U6" gate="A" pin="IN1"/>
<wire x1="22.86" y1="129.54" x2="17.78" y2="129.54" width="0.1524" layer="91"/>
<label x="5.08" y="129.54" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U6" gate="A" pin="IN2"/>
<wire x1="22.86" y1="121.92" x2="17.78" y2="121.92" width="0.1524" layer="91"/>
<label x="5.08" y="121.92" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U7" gate="A" pin="IN1"/>
<wire x1="81.28" y1="129.54" x2="76.2" y2="129.54" width="0.1524" layer="91"/>
<label x="63.5" y="129.54" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U7" gate="A" pin="IN2"/>
<wire x1="81.28" y1="121.92" x2="76.2" y2="121.92" width="0.1524" layer="91"/>
<label x="63.5" y="121.92" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U5" gate="A" pin="IN2"/>
<wire x1="81.28" y1="157.48" x2="76.2" y2="157.48" width="0.1524" layer="91"/>
<label x="63.5" y="157.48" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U5" gate="A" pin="IN1"/>
<wire x1="81.28" y1="165.1" x2="76.2" y2="165.1" width="0.1524" layer="91"/>
<label x="63.5" y="165.1" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U4" gate="A" pin="IN1"/>
<wire x1="22.86" y1="165.1" x2="17.78" y2="165.1" width="0.1524" layer="91"/>
<label x="5.08" y="165.1" size="1.778" layer="95"/>
</segment>
<segment>
<pinref part="U4" gate="A" pin="IN2"/>
<wire x1="22.86" y1="157.48" x2="17.78" y2="157.48" width="0.1524" layer="91"/>
<label x="5.08" y="157.48" size="1.778" layer="95"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
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
