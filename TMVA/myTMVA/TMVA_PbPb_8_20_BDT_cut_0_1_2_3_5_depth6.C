void c()
{
//=========Macro generated from canvas: c/the canvas
//=========  (Fri Jan 17 03:47:58 2020) by ROOT version6.02/13
   TCanvas *c = new TCanvas("c", "the canvas",200,22,650,500);
   gStyle->SetOptStat(0);
   c->Range(-0.128266,0.07692306,1.059382,1.102564);
   c->SetBorderMode(0);
   c->SetBorderSize(2);
   c->SetGridx();
   c->SetGridy();
   c->SetTickx(1);
   c->SetTicky(1);
   c->SetRightMargin(0.05);
   c->SetBottomMargin(0.12);
   c->SetFrameFillColor(0);
   c->SetFrameBorderMode(0);
   c->SetFrameBorderMode(0);
   
   TH2F *frame1 = new TH2F("frame1","Background rejection versus Signal efficiency",500,0,1,500,0.2,1);
   frame1->SetStats(0);
   frame1->SetLineWidth(2);
   frame1->SetMarkerStyle(21);
   frame1->SetMarkerSize(0.3);
   frame1->GetXaxis()->SetTitle("Signal efficiency");
   frame1->GetXaxis()->SetLabelOffset(0.012);
   frame1->GetXaxis()->SetTitleSize(0.045);
   frame1->GetXaxis()->SetTitleOffset(1.25);
   frame1->GetYaxis()->SetTitle("Background rejection");
   frame1->GetYaxis()->SetLabelOffset(0.012);
   frame1->GetYaxis()->SetTitleSize(0.045);
   frame1->GetYaxis()->SetTitleOffset(1.22);
   frame1->Draw("");
   
   TH1D *MVA_BDT_rejBvsS2 = new TH1D("MVA_BDT_rejBvsS2","MVA_BDT",100,0,1);
   MVA_BDT_rejBvsS2->SetBinContent(1,0.9996632);
   MVA_BDT_rejBvsS2->SetBinContent(2,0.9989511);
   MVA_BDT_rejBvsS2->SetBinContent(3,0.9980854);
   MVA_BDT_rejBvsS2->SetBinContent(4,0.9972429);
   MVA_BDT_rejBvsS2->SetBinContent(5,0.9963424);
   MVA_BDT_rejBvsS2->SetBinContent(6,0.9953099);
   MVA_BDT_rejBvsS2->SetBinContent(7,0.9941799);
   MVA_BDT_rejBvsS2->SetBinContent(8,0.9931813);
   MVA_BDT_rejBvsS2->SetBinContent(9,0.9921832);
   MVA_BDT_rejBvsS2->SetBinContent(10,0.991207);
   MVA_BDT_rejBvsS2->SetBinContent(11,0.9902789);
   MVA_BDT_rejBvsS2->SetBinContent(12,0.9888922);
   MVA_BDT_rejBvsS2->SetBinContent(13,0.9875511);
   MVA_BDT_rejBvsS2->SetBinContent(14,0.9863184);
   MVA_BDT_rejBvsS2->SetBinContent(15,0.9845832);
   MVA_BDT_rejBvsS2->SetBinContent(16,0.9833834);
   MVA_BDT_rejBvsS2->SetBinContent(17,0.9821627);
   MVA_BDT_rejBvsS2->SetBinContent(18,0.9805363);
   MVA_BDT_rejBvsS2->SetBinContent(19,0.978348);
   MVA_BDT_rejBvsS2->SetBinContent(20,0.9768349);
   MVA_BDT_rejBvsS2->SetBinContent(21,0.9748014);
   MVA_BDT_rejBvsS2->SetBinContent(22,0.9732534);
   MVA_BDT_rejBvsS2->SetBinContent(23,0.9718694);
   MVA_BDT_rejBvsS2->SetBinContent(24,0.9697111);
   MVA_BDT_rejBvsS2->SetBinContent(25,0.9677368);
   MVA_BDT_rejBvsS2->SetBinContent(26,0.9653169);
   MVA_BDT_rejBvsS2->SetBinContent(27,0.9634832);
   MVA_BDT_rejBvsS2->SetBinContent(28,0.9617869);
   MVA_BDT_rejBvsS2->SetBinContent(29,0.959799);
   MVA_BDT_rejBvsS2->SetBinContent(30,0.9580124);
   MVA_BDT_rejBvsS2->SetBinContent(31,0.9551597);
   MVA_BDT_rejBvsS2->SetBinContent(32,0.9529968);
   MVA_BDT_rejBvsS2->SetBinContent(33,0.9497587);
   MVA_BDT_rejBvsS2->SetBinContent(34,0.9472905);
   MVA_BDT_rejBvsS2->SetBinContent(35,0.9438335);
   MVA_BDT_rejBvsS2->SetBinContent(36,0.9415208);
   MVA_BDT_rejBvsS2->SetBinContent(37,0.9378881);
   MVA_BDT_rejBvsS2->SetBinContent(38,0.9348214);
   MVA_BDT_rejBvsS2->SetBinContent(39,0.9314108);
   MVA_BDT_rejBvsS2->SetBinContent(40,0.9280617);
   MVA_BDT_rejBvsS2->SetBinContent(41,0.9243761);
   MVA_BDT_rejBvsS2->SetBinContent(42,0.9193232);
   MVA_BDT_rejBvsS2->SetBinContent(43,0.9158156);
   MVA_BDT_rejBvsS2->SetBinContent(44,0.9124115);
   MVA_BDT_rejBvsS2->SetBinContent(45,0.907858);
   MVA_BDT_rejBvsS2->SetBinContent(46,0.9045294);
   MVA_BDT_rejBvsS2->SetBinContent(47,0.8984555);
   MVA_BDT_rejBvsS2->SetBinContent(48,0.8934761);
   MVA_BDT_rejBvsS2->SetBinContent(49,0.8879123);
   MVA_BDT_rejBvsS2->SetBinContent(50,0.8832915);
   MVA_BDT_rejBvsS2->SetBinContent(51,0.8791164);
   MVA_BDT_rejBvsS2->SetBinContent(52,0.8737834);
   MVA_BDT_rejBvsS2->SetBinContent(53,0.8677923);
   MVA_BDT_rejBvsS2->SetBinContent(54,0.8644374);
   MVA_BDT_rejBvsS2->SetBinContent(55,0.8595654);
   MVA_BDT_rejBvsS2->SetBinContent(56,0.8536027);
   MVA_BDT_rejBvsS2->SetBinContent(57,0.8471992);
   MVA_BDT_rejBvsS2->SetBinContent(58,0.8409022);
   MVA_BDT_rejBvsS2->SetBinContent(59,0.8356302);
   MVA_BDT_rejBvsS2->SetBinContent(60,0.8314074);
   MVA_BDT_rejBvsS2->SetBinContent(61,0.8269973);
   MVA_BDT_rejBvsS2->SetBinContent(62,0.8232055);
   MVA_BDT_rejBvsS2->SetBinContent(63,0.8158377);
   MVA_BDT_rejBvsS2->SetBinContent(64,0.8065279);
   MVA_BDT_rejBvsS2->SetBinContent(65,0.799815);
   MVA_BDT_rejBvsS2->SetBinContent(66,0.7915079);
   MVA_BDT_rejBvsS2->SetBinContent(67,0.7848585);
   MVA_BDT_rejBvsS2->SetBinContent(68,0.7793072);
   MVA_BDT_rejBvsS2->SetBinContent(69,0.7717161);
   MVA_BDT_rejBvsS2->SetBinContent(70,0.7640754);
   MVA_BDT_rejBvsS2->SetBinContent(71,0.7569312);
   MVA_BDT_rejBvsS2->SetBinContent(72,0.7510796);
   MVA_BDT_rejBvsS2->SetBinContent(73,0.7417);
   MVA_BDT_rejBvsS2->SetBinContent(74,0.7316387);
   MVA_BDT_rejBvsS2->SetBinContent(75,0.7230047);
   MVA_BDT_rejBvsS2->SetBinContent(76,0.713365);
   MVA_BDT_rejBvsS2->SetBinContent(77,0.7041748);
   MVA_BDT_rejBvsS2->SetBinContent(78,0.6920184);
   MVA_BDT_rejBvsS2->SetBinContent(79,0.6822404);
   MVA_BDT_rejBvsS2->SetBinContent(80,0.6716924);
   MVA_BDT_rejBvsS2->SetBinContent(81,0.6611507);
   MVA_BDT_rejBvsS2->SetBinContent(82,0.6503612);
   MVA_BDT_rejBvsS2->SetBinContent(83,0.6384351);
   MVA_BDT_rejBvsS2->SetBinContent(84,0.6232737);
   MVA_BDT_rejBvsS2->SetBinContent(85,0.6041628);
   MVA_BDT_rejBvsS2->SetBinContent(86,0.5832644);
   MVA_BDT_rejBvsS2->SetBinContent(87,0.5675232);
   MVA_BDT_rejBvsS2->SetBinContent(88,0.5402928);
   MVA_BDT_rejBvsS2->SetBinContent(89,0.5202664);
   MVA_BDT_rejBvsS2->SetBinContent(90,0.4932404);
   MVA_BDT_rejBvsS2->SetBinContent(91,0.4686974);
   MVA_BDT_rejBvsS2->SetBinContent(92,0.4454239);
   MVA_BDT_rejBvsS2->SetBinContent(93,0.4178902);
   MVA_BDT_rejBvsS2->SetBinContent(94,0.3979961);
   MVA_BDT_rejBvsS2->SetBinContent(95,0.3733232);
   MVA_BDT_rejBvsS2->SetBinContent(96,0.3347756);
   MVA_BDT_rejBvsS2->SetBinContent(97,0.2857266);
   MVA_BDT_rejBvsS2->SetBinContent(98,0.2353376);
   MVA_BDT_rejBvsS2->SetBinContent(99,0.1777826);
   MVA_BDT_rejBvsS2->SetBinContent(100,0.0778047);
   MVA_BDT_rejBvsS2->SetEntries(100);
   MVA_BDT_rejBvsS2->SetLineWidth(3);
   MVA_BDT_rejBvsS2->GetXaxis()->SetTitle("Signal eff");
   MVA_BDT_rejBvsS2->GetXaxis()->SetLabelFont(42);
   MVA_BDT_rejBvsS2->GetXaxis()->SetLabelSize(0.035);
   MVA_BDT_rejBvsS2->GetXaxis()->SetTitleSize(0.035);
   MVA_BDT_rejBvsS2->GetXaxis()->SetTitleFont(42);
   MVA_BDT_rejBvsS2->GetYaxis()->SetTitle("Backgr rejection (1-eff)");
   MVA_BDT_rejBvsS2->GetYaxis()->SetLabelFont(42);
   MVA_BDT_rejBvsS2->GetYaxis()->SetLabelSize(0.035);
   MVA_BDT_rejBvsS2->GetYaxis()->SetTitleSize(0.035);
   MVA_BDT_rejBvsS2->GetYaxis()->SetTitleFont(42);
   MVA_BDT_rejBvsS2->GetZaxis()->SetLabelFont(42);
   MVA_BDT_rejBvsS2->GetZaxis()->SetLabelSize(0.035);
   MVA_BDT_rejBvsS2->GetZaxis()->SetTitleSize(0.035);
   MVA_BDT_rejBvsS2->GetZaxis()->SetTitleFont(42);
   MVA_BDT_rejBvsS2->Draw("csame");
   
   TH2F *frame3 = new TH2F("frame3","Background rejection versus Signal efficiency",500,0,1,500,0.2,1);
   frame3->SetStats(0);
   frame3->SetLineWidth(2);
   frame3->SetMarkerStyle(21);
   frame3->SetMarkerSize(0.3);
   frame3->GetXaxis()->SetTitle("Signal efficiency");
   frame3->GetXaxis()->SetLabelOffset(0.012);
   frame3->GetXaxis()->SetTitleSize(0.045);
   frame3->GetXaxis()->SetTitleOffset(1.25);
   frame3->GetYaxis()->SetTitle("Background rejection");
   frame3->GetYaxis()->SetLabelOffset(0.012);
   frame3->GetYaxis()->SetTitleSize(0.045);
   frame3->GetYaxis()->SetTitleOffset(1.22);
   frame3->Draw("sameaxis");
   
   TLegend *leg = new TLegend(0.15,0.171,0.5,0.281,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextFont(62);
   leg->SetLineColor(34);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("NULL","MVA Method:","h");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("MVA_BDT_rejBvsS","BDT","l");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   leg->Draw();
   
   TPaveText *pt = new TPaveText(0.01,0.9339831,0.71,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#5d6b7d");
   pt->SetFillColor(ci);
   pt->SetLineColor(34);
   pt->SetTextColor(0);
   TText *AText = pt->AddText("Background rejection versus Signal efficiency");
   pt->Draw();
  
// ------------>Primitives in pad: imgpad
   TPad *imgpad = new TPad("imgpad", "imgpad",0.7892569,0.91,0.95,0.965);
   imgpad->Draw();
   imgpad->cd();
   imgpad->Range(0,0,1,1);
   imgpad->SetFillColor(0);
   imgpad->SetBorderMode(0);
   imgpad->SetBorderSize(2);
   imgpad->SetTickx(1);
   imgpad->SetTicky(1);
   imgpad->SetLeftMargin(0);
   imgpad->SetRightMargin(0);
   imgpad->SetTopMargin(0);
   imgpad->SetBottomMargin(0);
   imgpad->SetFrameBorderMode(0);
   imgpad->SetFrameLineColor(0);
   imgpad->SetFrameBorderMode(0);

/* XPM */
const char *xpm_tmva_logo_gif_1[] = {
/* columns rows colors chars-per-pixel */
"103 25 89 1",
"  c #6A4F7B",
". c #67557B",
"X c #75597A",
"o c #FF0303",
"O c #FF1919",
"+ c #FF2A09",
"@ c #FF3D0C",
"# c #FF2020",
"$ c #FF3A3A",
"% c #FF6012",
"& c #FF7B18",
"* c #B17B58",
"= c #8B646A",
"- c #936964",
"; c #FF4444",
": c #FF5252",
"> c #FF6D6D",
", c #FF7E6A",
"< c #FF7979",
"1 c #34399B",
"2 c #3536A0",
"3 c #423C91",
"4 c #3F409E",
"5 c #49408D",
"6 c #5E4B81",
"7 c #464197",
"8 c #624E81",
"9 c #695180",
"0 c #4444A5",
"q c #5D5DAD",
"w c #5D5DB3",
"e c #6C62A3",
"r c #6D6DB9",
"t c #7474B8",
"y c #7D7DC3",
"u c #D37C95",
"i c #FF881B",
"p c #FF9E1F",
"a c #D28E3F",
"s c #FF8721",
"d c #F59F2A",
"f c #E79833",
"g c #FFA621",
"h c #FFAE30",
"j c #FFB237",
"k c #BE824C",
"l c #CD8B45",
"z c #D38D40",
"x c #D79540",
"c c #FFB845",
"v c #FFBE54",
"b c #F2BC6D",
"n c #FFC25D",
"m c #FFC360",
"M c #FFC673",
"N c #9183AB",
"B c #8B81B2",
"V c #FF8686",
"C c #FFAFAF",
"Z c #FFBFBF",
"A c #8686C6",
"S c #9C9CCC",
"D c #9B9BD1",
"F c #A0A0D3",
"G c #B9B9DB",
"H c #BEBEE2",
"J c #C6BBC9",
"K c #D3B2CC",
"L c #FFD48B",
"P c #FFDB9E",
"I c #E3CBBF",
"U c #FFDEAF",
"Y c #FFDFB7",
"T c #FFE1AC",
"R c #FFE8BD",
"E c #D3C2C1",
"W c #FFC2C2",
"Q c #F9D9DF",
"! c #CCCCEB",
"~ c #D3CCE5",
"^ c #D0D0EC",
"/ c #DDDDF1",
"( c #FFEBC3",
") c #FFEDD2",
"_ c #FFF0D3",
"` c #E7E7F6",
"' c #FFF8E4",
"] c #FFFFFF",
"[ c None",
"]]]]]]]]]]]]]]]]]](mggjM_]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]",
"]]]]]]]]]]]]]]]]]ngggggggT]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]",
"]]]]]]]]]]]]]]]]LgggggggggR]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]",
"]]]]]]]]]]]]]]]'ggggggggggc]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]",
"]]]]]]]]]]]]]]]Lggggggggggg_]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]",
"]]]]]]]]]]]]]]]ngggggggggggP]]]]]]]]]]]]]]WWZWWWZWWWZQ^!^^]]]]]]^!^^]]!^!]]]]]]]!^!]]]]]/^!^]]]]]]]]]]]",
"]]]]]]]]]]]]]]]ngggggggggggP]]]]]]]]]]]]]Wooooooooooou1124]]]]]F112q]`112S]]]]]S12t]]]]]0112F]]]]]]]]]]",
"]]]]]]]]]]]]]]]Lggggggggggg(]]]]]]]]]]]]]<oooooooooooK1211F]]]]2112q]]q210]]]]]q12G]]]]H1121q]]]]]]]]]]",
"]]]]]]]]]]]]]]](ggggggggggg]]]]]]]]]]]]]]QWWZ<oooCWWW~11210]]]G1211w]]G211!]]]!110]]]]]r11211/]]]]]]]]]",
"]]]]]]]]]]]]]]]]vgggggggggP]]]]]]]]]]]]]]]]]]>oo#]]]]^12111F]]r1121w]]]211D]]]A11y]]]]]121011D]]]]]]]]]",
"]]]]]]]]]]]]]]]]'jgggggggv]]]]]]]]]]]]]]]]]]];oo>]]]]^121q1w]!11w11w]]]t12q]]]011H]]]]F11yG11w]]]]]]]]]",
"]]]]]]]]]]]]]]]](MLggggjUL']]]]]]]]]]]]]]]]]]oooC]]]]^121S21!q10A11w]]]H112`]G210]]]]]r11!]121^]]]]]]]]",
"]]]]]]]]'((((_]]M]]'(U(]]]m]](((((]]]]]]]]]]WoooQ]]]]^121`11012GA11w]]]]121F]t21A]]]]]210]]r11A]]]]]]]]",
"]]]]]]]_']]]]](M]]]]]]]]]]'v(]]]]](']]]]]]]]VooO]]]]]^121]t2110]A11w]]]]r11w]121!]]]]F11t]]D110]]]]]]]]",
"]]]]]]_]]]]]]]](]]]]]]]]]]]_]]]]]]]'']]]]]]]$oo:]]]]]^121]/111A]A11w]]]]H112S110]]]]]q210qr0112!]]]]]]]",
")((((R]]]]]]]]]](((((((((((]]]]]]]]]((((((((ooo,(((((E111((e11I(B11q(((((711211N((((J1121112111t((((((_",
"cggggL]]]]]]]]]]Uggggggggg']]]]]]]]]]cgggggiooo&gggggz111ggggggg=126ggggg-11211lgggg=123.9 96125ggggggv",
"cgggg(]]]]]]]]]]_ggggggggc]]]]]]]]]]]Lggggg%ooopgggggz111ggggggg=126gggggf11217ggggd111*ggggf112lgggggv",
"cgggg(]]]]]]]]]]_ggggggggv]]]]]]]]]]]Pggggg@oo+ggggggz111ggggggg=126gggggg8111-ggggk123gggggg611Xgggggv",
"cgggg(]]]]]]]]]]_ggggggggj]]]]]]]]]]]Mgggggi&isgggggggzlagggggggflaxggggggflalgggggflaxggggggflalgggggn",
"cggggP]]]]]]]]]]Rggggggggg']]]]]]]]]]cggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggv",
"cggggj]]]]]]]]]]ngggggggggP]]]]]]]]](gggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggn",
"cgggggv]]]]]]]]Pggggggggggg_]]]]]]]'hgggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggn",
"cggggggm]]]]]]Lggggggggggggg(]]]]](cggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggv",
"bnvnvnvnmY((RMnvnvnvnvnvnvnvnP(((UnvnvnvnvnvnvnvnvnvnvnvnvnvnvnvnvnvnvnvnvnvnvnvnvnvnvnvnvnvnvnvnvnvnvL"
};


   TImage *xpm_tmva_logo_gif_1_img = TImage::Create();
   xpm_tmva_logo_gif_1_img->SetImageBuffer( (char **)xpm_tmva_logo_gif_1, TImage::kXpm);
   xpm_tmva_logo_gif_1_img->Draw();
   imgpad->Modified();
   c->cd();
   c->Modified();
   c->cd();
   c->SetSelected(c);
}
