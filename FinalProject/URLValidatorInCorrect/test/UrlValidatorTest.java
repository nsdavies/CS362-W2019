

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest() {
      // ---------------- Manual testing of isValid -------------------------
      String[] schemes = { "http", "https" };
      UrlValidator urlValidator = new UrlValidator(schemes);

      // -----------------tests that should work-----------------------------
      assertTrue(urlValidator.isValid("http://www.google.com"));
      assertTrue(urlValidator.isValid("https://www.reddit.com/"));
      assertTrue(urlValidator.isValid("https://en.wikipedia.org/wiki/Reddit#Controversies"));
      assertTrue(urlValidator.isValid(
            "https://longurlmaker.com/go/?id=ShoterLinktalla80115f9490tall44MetamarkTinyLink1high0stretchedlingering0toweringkdrawnZouta41EzURLlastingdlingeringfRedirx1FhURLprolongedDwarfurlk41wfremote0x1TightURLgreatelongated9FwdURL69kTinyURL3expandedNanoRefShredURLBeamZtolongish04TinyLink11ganglingsustainedfarawaygreat5e0gangling9561tdistanta108NutshellURL38lnkZin19LiteURL1remote18URLcutfarawayc5CanURLc01WapURL1WapURLlankyf1ucqcontinued04UrlTearunning9ShrinkURL11e4x2fXZse50farZreaching9c701SnipURL9ShortlinksPiURLrunningenlargedeRubyURL71e8continuedB65128tallstretchingelongated72g2a4gShrinkURL4enlarged71f950lengthyCanURL9fprolonged0faraway217l99EzURLsustainedcontinued66URlZie1ShortURLstretching01ShredURL05s064lofty81telongatedEzURL309c9elongated85l5ShrinkURLTightURLt00074continued55tYepIt901SHurlprolonged777350Fly2w0ShoterLinkb4lastingprotracted5153outstretched489Sitelutions0a7LiteURLelongated136Xilk1greatMooURL096s08TinyURL19070Minilien25101sStartURL151072rangy710Ne11eShim06continuedlankyfarZreachingaDwarfurl3lingering9Smallr03longishcontinueddrawnZouttG8LShoterLink0stretch62Fly2G8La0outstretchedMyURLelongatedprolongedr710DwarfurlShrinkURL913jURLZcoZuklURLcut6Metamark3olastingprolongedNanoRefc902Smallr1elongate0spunZout10015UrlTea1lanky4stringydrawnZout0519extensivestretchinglanky4xCanURL1lofty00continuedfarZoff6181DecentURL3stretch9farZoffTinyURLURlZie4581remoten17farZoffShim0001s1fkstretchlongishDoiopSitelutions13remoteuG8L104EasyURL1TraceURLm7Shorl5SimURLz82sBeamZto1espunZoutGetShorty30564f4FhURLzs8farZreachingstretched4enduringv8i1TinyURLremote1183x301URL1stretchedYATUC7t06pnMetamarkgangling48mf3d7lingering0remoteg0distant118Shrtnd1NanoRef73ca0lastingx40f1831drawnZoutLiteURL7BeamZto80d011continuedSmallrd2enlargedYepItuc9running9PiURL0enlarged0enduringfarZreachinggangling118dsustained1110SHurl10WapURL99vlasting1ab301URL2ltallBeamZto680RubyURL401WapURL0enduring1f1URLZcoZuk2yA2Nw4b00Doiop5k962Fly20f0TinyURLShortURLfarZreachingNotLong0411stringyr101ab1DecentURL706stretch1duEasyURLhelongate7u040Dwarfurldeepdistantva10b9ca7MooURL9s3lingering1s11MooURL31kXilB"));

      // -----------------tests that should not work-------------------------
      assertFalse(urlValidator.isValid("https://www.reddit.com2/"));
      assertFalse(urlValidator.isValid("https://fishnuggets"));
      assertFalse(urlValidator.isValid("htps://longurlmaker.com/"));
      assertFalse(urlValidator.isValid("://longurlmaker.com/"));
      assertFalse(urlValidator.isValid("https//longurlmaker.com/"));
      assertFalse(urlValidator.isValid("https:longurlmaker.com/"));
      assertFalse(urlValidator.isValid("longurlmaker.com/"));
      assertFalse(urlValidator.isValid("https://longurlmaker/"));
   }
   
   
   public void testYourFirstPartition()
   {
	 //You can use this function to implement your First Partition testing	   

   }
   
   public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing	   

   }
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid()
   {
	   //You can use this function for programming based testing

   }
   


}
