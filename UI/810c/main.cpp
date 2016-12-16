
#include <fstream>
#include <string>
#include <string.h>
#include <locale>
#include <wchar.h>
#include <cstdio>
#include <cstdlib>
#include <qstring.h>
#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <page.h>
#include <qdir.h>
#include <text.h>

using namespace std;
wstring ncx[500][2];//windows组做目录用,name and src
struct Set{
    string color = "default";
    string font = "default";
    string size = "16px";
    string bold = "0";
    string italic = "0";
    string underline = "0";
};
Set bodydefault;
class TRANS{
private:
    string path;
    wstring bodytrans;
    string allsetting;
    QString qimgset;
public:
    TRANS(wstring bodytrans,string allsetting,QString qimgset):bodytrans(bodytrans),allsetting(allsetting),qimgset(qimgset){}
    string getallsetting(){return allsetting;}
    wstring getbodytrans(){return bodytrans;}
    QString getqimgset(){return qimgset;}
};

string wtos(wstring wstr);
wstring stow(string str);
TRANS texttrans(string htmlpath1);
string wtos(wstring wstr){
    QString qstr = QString::fromStdWString(wstr);
    string str = qstr.toStdString();
    return str;
}
wstring stow(string str){
    QString qstr = QString::fromStdString(str);
    wstring wstr = qstr.toStdWString();
    return wstr;
}
string settingdetail(string fullsetting,string settingname);
string getsetting(string cssfile, string settingname);
wstring wopenfile(string path);
string openfile(string path);
string openfile(string path){
    string buf;
    ifstream file;
    file.open(path);
    if(!file){
        cout<<"open file err";
    }
    string src = "";
    while(!file.eof()){
        getline(file,buf);
        if(buf.length() == 0)
        {
            continue;
        }
        src+=buf;
        //cout << src<<endl;
    }
    //cout << src<<endl;
    file.close();
    return src;
}
wstring wopenfile(string path){
    wstring wbuf;
    wifstream wfile;
    wfile.open(path);
    if(!wfile){
        cout<<"open wfile err";
    }
    wstring src = L"";
    while(!wfile.eof()){
        getline(wfile,wbuf);
      /*  if(wbuf.length() == 0)
        {
            continue;
        }*/
        src+=wbuf;
        //wcout << src<<endl;
    }
    //wcout << src<<endl;
    wfile.close();
    return src;
}
void getncx(wstring fullncx,int pos,int i){
    if(fullncx.find(L"playOrder",pos) != wstring::npos){
        int postext1 = fullncx.find(L"<text>",fullncx.find(L"playOrder",pos));
        int postext2 = fullncx.find(L"</text>",postext1+6);
        ncx[i][0] = fullncx.substr(postext1+6,postext2-postext1-6);
        int possrc1 = fullncx.find(L"src=",fullncx.find(L"playOrder",pos));
        int possrc2 = fullncx.find(L"\"",possrc1+5);
        ncx[i][1] = fullncx.substr(possrc1+5,possrc2-possrc1-5);
        //wcout << ncx[i][0]<<'\n'<<ncx[i][1]<<endl;
        if(fullncx.find(L"playOrder",possrc2)!=wstring::npos){
            i++;
            getncx(fullncx,possrc2,i);
        }
        return;
    }
    return;
}

int main(int argc, char *argv[]) {
    //string ncxpath = "C:\\Users\\lenovo\\Desktop\\Little Women\\OEBPS\\toc.ncx";//path of ncx file
    //wstring fullncx = wopenfile(ncxpath);
    //getncx(fullncx,0,0);
    QString path = QDir::currentPath();
    string st=path.toStdString();
    cout<<st<<endl;

    string htmlpath1= "content2478944_41850213.html";//Address of html file
    TRANS output = texttrans(htmlpath1);//Function to transfer html to given standard
    QApplication a(argc, argv);
    MainWindow w;
    wofstream testf;

    testf.open("testfile.txt");
    testf << output.getbodytrans();
    testf.close();

   //Start test




#if 0
    cout<<"*********************"<<endl;
    //const wstring allwords1=L"青光闪动，一柄青钢剑倏地刺出，指向在年汉子左肩，使剑少年不等招用老，腕抖剑斜，剑锋已削向那汉子右颈。那中年汉子剑挡格，铮的一声响，双剑相击，嗡嗡作声，震声未绝，双剑剑光霍霍，已拆了三<n>招，中年汉子长剑猛地击落，直砍少年顶门。那少年避向右侧，左手剑诀一引，青钢剑疾刺那汉子大腿。<n><stylechange>两人剑法迅捷，全力相搏。<n><stylechange>练武厅东坐着二人。上首是个四十左右的中年道姑，铁青着脸，嘴唇紧闭。下首是个五十余岁的老者，右手捻着长须，神情甚是得意。两人的座位相距一丈有余，身后各站着二十余名男女弟子。西边一排椅子上<n>坐着十余位宾客。东西双方的目光都集注于场中二人的角斗。<n><stylechange>眼见那少年与中年汉子已拆到七十余招，剑招越来越紧，兀自未分胜败。突然中年汉子一剑挥出，用力猛了，身子微微一幌，似欲摔跌。西边宾客中一个身穿青衫的年轻男子忍不住“嗤”的一声笑。他随即知道失态，忙伸手按住了口。<stylechange>便在这时，场中少年左手呼一掌拍出，击向那汉子后心，那汉子向前跨出一步避开，手中长剑蓦地圈转，喝一声：“着！”那少年左腿已然中剑，腿下一个踉跄，长剑在地下一撑，站直身子待欲再斗，那中年汉<n>子已还剑入鞘，笑道：“褚师弟，承让、承让，伤得不厉害么？”那少年脸色苍白，咬着嘴唇道：“多谢龚师兄剑下留情。”<n><stylechange>那长须老者满脸得色，微微一笑，说道：“东宗已胜了三阵，看来这‘剑湖宫’又要让东宗再住五年了。辛师妹，咱们还须比下去么？”坐在他上首的那中年道姑强忍怒气，说道：“左师果然调教得好徒儿。但<n>不知左师兄对‘无量玉壁’的钻研，这五年来可已大有心得么？”长须老者向她瞪了一眼，正色道：“师妹怎地忘了本派的规矩？”那道姑哼了一声，便不再说下去了。<n><stylechange>这老者姓左，名叫子穆，是“无量剑”东宗的掌门。那道姑姓辛，道号双清，是“无量剑”西宗掌门。<n><stylechange>“无量剑”原分东、北、西三宗，北宗近数十年来已趋式微，东西二宗却均人才鼎盛。“无量剑”于五代后唐年间在南诏无量山创派，掌门人居住无量山剑湖宫。自于大宋仁过年间分为三宗之后，每隔五年，三<n>宗门下弟子便在剑湖宫中比武斗剑，获胜的一宗得在剑湖宫居住五年，至第六年上重行比试。五场斗剑，赢得三场者为胜。这五年之中，败者固然极力钻研，以图在下届剑会中洗雪前耻，胜者也是丝毫不敢松懈。北<n>宗于四十年前获胜而入住剑湖宫，五年后败阵出宫，掌门人一怒而率领门人迁往山西，此后即不再参预比剑，与东西两宗也不通音问。三十五年来，东西二宗互有胜负。东宗胜过四次，西宗胜过两次。那龚姓中年汉<n>子与褚姓少年相斗，已是本次比剑中的第四场，姓龚的汉子既胜，东宗四赛三胜，第五场便不用比了。<n><stylechange>西首锦凳上所坐的则是别派人士，其中有的是东西二宗掌门人共同出面邀请的公证人，其余则是前来观礼的嘉宾。这些人都是云南武林中的知名之士。只坐在最下首的那个青衣少年却是个无名之辈，偏是他在龚<n>姓汉子伴作失足时嗤的一声笑。这少年乃随滇南普洱老武师马五德而来。马五德是大茶商，豪富好客，颇有孟尝之风，江湖上落魄的武师前去投奔，他必竭诚相待，因此人缘甚佳，武功却是平平。左子穆听马五德引<n>见之时说这少年姓段，段姓是大理国的国姓，大理境内姓段的成千成万，左子穆当时听了也不以为意，心想分多半是马五德的弟子，这马老儿自身的功夫稀松平常，调教出来的弟子还高得到那里去，是以连“久<n>仰”两字也懒得说，只拱了拱手，便肃入宾座。不料这年轻人不知天高地厚，竟当左子穆的得意弟子佯出虚招诱敌之时，失笑讥讽。<n><stylechange>当下左子穆笑道：“辛师妹今年派出的四名弟子，剑术上的造诣着实可观，尤其这第四场我们赢得更是侥幸。褚师侄年纪轻轻，居然练到了这般地步，前途当真不可限量，五年之后，只怕咱们东西宗得换换位<n>了，呵呵，呵呵！”说着大笑不已，突然眼光一转，瞧向那姓段青年，说道：“我那劣徒适才以虚招‘跌扑步’获胜，这位段世兄似乎颇不以为然。便请段世兄下场指点小徒一二如何？马五哥威震滇南，强将手下无<n>弱兵，段世兄的手段定是挺高的。”<n><stylechange>马五德脸上微微一红，忙道：“这位段兄弟不是我的弟子。你老哥哥这几手三脚猫的把式，怎配做人家师父？左贤弟可别当面取笑。这位段兄弟来到普洱舍下，听说我正要到无量山来，便跟着同来，说道无量山<n>山水清幽，要来赏玩风景。”<n><stylechange>左子穆心想：“他若是你弟子，碍着你的面子，我也不能做得太绝了，既是寻常宾客，那可不能客气了。有人竟敢在剑湖宫中讥笑‘无量剑’东宗的武功，若不教他闹个灰头土脸下的山，姓左的颜面何存？”当<n>下冷笑一声，说道：“请教段兄大号如何称呼，是那一位高人的门下？”<n><stylechange>那姓段青年微笑道：“在下单名一誉字，从来没学过什么武艺。我看到别人摔交，不论他真摔还是假摔，忍不住总是要笑的。”左子穆听他言语中全无恭敬之意，不禁心中有气，道：“那有什么好笑？”段誉轻<n>摇手中摺扇，轻描淡写的道：“一个人站着坐着，没什么好笑，躺在床上，也不好笑，要是躺地下，哈哈，那就可笑得紧了。除非他是个三岁娃娃，那又作别论。”左子穆听他说话越来越狂妄，不禁气塞胸臆，向马<n>五德道：“马五哥，这位段兄是你的好朋友么？”<n><stylechange>马五德和段誉也是初交，完全不知对方底细，他生性随和，段誉要同来无量山，他不便拒却，便带着来了，此时听左穆的口气甚是着恼，势必出手便极厉害，大好一个青年，何必让他吃个大亏？便道：“段兄弟<n>和我虽无深交，咱们总是结伴来的。我瞧段兄弟斯斯文文的，未必会什么武功，适才这一笑定是出于无意。这样吧，老哥哥肚子也饿了，左贤弟赶快整治酒席，咱们贺你三杯。今日大好日子，左贤弟何必跟年轻晚辈<n>计较？”<n><stylechange>左子穆道：“段兄既然不是马五哥的好朋友，那么兄弟如有得罪，也不算是扫了马五哥的金面。光杰，刚才人家笑你呢，你下场请教请教吧。”<n><stylechange>那中年汉子龚光杰巴不得师父有这句话，当下抽出长剑，往场中一站，倒转剑柄，拱手向段誉道：“段朋友，请！”段誉道：“很好，你练罢，我瞧着。”仍是坐在椅中，并不起身。龚光杰登时脸皮紫胀，怒<n>道：“你……你说什么？”段誉道：“你手里拿了一把剑这么东晃来西去，想是要练剑，那么你就练罢。我向来不爱瞧人家动刀使剑，可是既来之，则安之，那也不防瞧着。”龚光杰喝道：“我师父叫你这小子也下<n>场来，咱们比划比划。”<n><stylechange>段誉轻挥折扇，摇了摇头，说道：“你师父是你的师父，你师父可不是我的师父。你师父差得动你，你师父可差不动我。你师父叫你跟人家比剑，你已经跟人家比过了。你师父叫我跟你比剑，我一来不会，二来<n>怕输，三来怕痛，四来怕死，因此是不比的。我说不比，就是不比。”<n><stylechange>他这番说什么“你师父”“我师父”的，说得犹如拗口令一般，练武厅中许多人听着，忍不住笑了出来。“无量剑”西宗双清门下男女各占其半，好几名女弟子格格娇笑。练武厅上庄严肃穆的气象，霎时间一扫<n>无遗。<n><stylechange>龚光杰大踏步过来，伸剑指向段誉胸口，喝道：“你到底是真的不会，还是装傻？”段誉见剑尖离胸不过数寸，只须轻轻一送，便刺入了心脏，脸上却丝毫不露惊慌之色，说道：“我自然是真的不会，装傻有什<n>么好装？”龚光杰道：“你到无量山剑湖宫中来撒野，想必是活得不耐烦了。你是何人门下？受谁的指使？若不直说，莫怪大爷剑下无情。”<n><stylechange>";
    wcout<<output.getbodytrans()<<endl;
     cout<<"*********************"<<endl;
    cout<<output.getallsetting()<<endl;
     cout<<"*********************"<<endl;


 #endif
    const wstring allwords1=L"第20章 危机降临 \n<stylechange> \nPS：亲，求几张推荐票！\n“你确定需要接受这个任务？不再更改其它任务？你要知道，这是三星任务，黑水山脉，猎杀五阶妖兽风火熊？现在的你，绝对不是对手。”\n工作台上，一位貌相不错的白衣女子，忍不住提醒对方。\n五级妖兽，风火熊，黑水山脉，群居的一种妖兽，拥有强悍防御能力，又具有风火双系攻击，名声非常响亮。\n一般上，外门弟子，不到武道六重天，绝对不单独挑战这一类妖兽。\n“不需要，三星任务，我接了！”\n<stylechange>众多任务之中，林飞选择三星任务，因为这一门任务，奖励丰富，又可以提升实力，这其中，重要一点，通过挑战群居妖兽，修炼《金刚不坏之身》，提升自己的防御能力。\n.......\n登记三星任务后。\n林飞转身离开，不打算继续留在这里。\n“喂，你忘了拿东西！”\n背后，忽然响起女子的声音。\n“东西？”林飞恍然大悟，自己真的忘记拿东西，那是关于风火熊的具体资料记载。\n悬赏区相关事情，林飞不过是前任“林飞”留下来，了解并不算太多。忽略资料的事情，再正常不过。\n<stylechange>果然，女子递上来一份资料，美眸里带着一抹的好奇。\n“这位师弟，风火熊不是这么好对付，师姐还是劝你，放弃这个任务，你要明白，任务失败，必须扣除功勋值，失去功勋值，将会影响到玄功，黄阶玄功，兑换…..”\n工作台上的女子，年约十七八岁，身穿一套淡白色衣裙，容貌尚不算出色，却也是难得一见的美女，樱桃小嘴上，挂着淡淡的欢笑，透着少女活泼气氛。\n“谢谢师姐的好意，我这个人喜欢各种挑战，有挑战才有各种生活。”林飞开口笑道，说罢，拿着资料，直接离开。\n白衣女孩，嘴上哼了哼，“哼哼，好狂妄的小子，本小姐劝你，不给脸色，诅咒你倒霉！”\n话音落下，白衣女孩身后再次出现一个女子，旋即响起空灵一般的声音，宛如山水之间，叮咚流过的溪水。\n“悠悠，你在气什么呢？”\n“青幽姐，你出关啦！”\n<stylechange>白衣女孩跑出来，一下子抱住青衣女子，好不高兴的样子，惹来旁边不少人羡慕妒忌的眼光，恨不得自己成为那一个女子。\n“当然啦，要是不出来，我怎么会知道，咱们的悠悠，好像看上什么人，莫非是在思春，想男人？”青衣女子嫣然一笑，如百花盛开。\n“哼哼，青幽姐，你好坏啊，你才想男人了。”\n……\n从悬赏区出来。\n外面仍然有不少人前来悬赏区接受悬赏任务，争取完成各种任务，获取足够的功勋值，要么便是获得大量银子。\n玄天大陆，一个武者的世界。\n一个武者想要出人头地，威震大陆，各种强横玄功，首要立足之本，黄阶玄功还是其次，作为外门弟子，修炼合适自己的玄功，需要天文数字的银两，同样需要打量功勋值。\n<stylechange>一本二三流玄功，动不动几千银子。\n一本黄阶玄功，动不动上万银子。\n仅仅玄功之上，花费的银子，想来都是一件恐怖的数字。\n武者玄功修炼少，对敌上将会吃很大的亏，两人相同实力，结果另外一方，修炼几门玄功，再加上黄阶玄功，足够压制对方。\n神武门之中，家族弟子，寒门弟子，想要获取玄功，需要获取各种功勋值。\n悬赏区，才会如今的繁荣。\n神武门通过弟子，完成各种任务，双方都可以获得好处。\n林飞很明白，刚才那女子的提醒，一般人真不敢去对付风火熊，其中危险性很大。弄不好死在上面。\n<stylechange>“谁让低阶妖兽经验值不给力，老子何苦猎杀五阶妖兽，纯粹自己给自己找不自在，可惜了….对了，貌似刚才那女孩不错，粉嫩可爱，若是可以勾搭一下，一尝芳泽那就爽了。”\n……\n“林飞，你终于舍得出来，不枉费我一直在这等你。”\n正当林飞想入非非的时候，一声低沉带着愤怒的声音，从正前方传过来。\n愤怒的声音，立刻引起众多弟子的注意。\n因为，这里是悬赏区门口。\n“天那，那不是林飞吗？”\n“林飞算什么，你不如看看，那边站着什么人？”\n<stylechange>“什么人，值得….什么，他怎么来了，难道是冲着林飞来的？”\n“张万山师兄怎么可能出现在这，最近不是传闻，他不是在修炼一门玄功吗，莫非因为弟弟张重山之事？”\n“一定是这样的，林飞曾经大发神威打伤张重山，后来又打败张风浪，想不到将张万山这一尊外门高手逼迫出来！”\n“林飞要倒霉了，张万山师兄一生气，谁都挡不住怒火。”\n……..\n当众外门弟子，目光落在那散发着冷冽气息的年轻人身上时，全都下意识打了一身寒颤，宛如深处在冰天雪地之中，不由自主离开这范围。躲避那冰冷气息。\n张万山，武道八重天，罡气高手！\n提起这个名字，外门弟子之中，无人不知，无人不晓，凡是达到武道八重天，罡气护身，都有望成为玄者。\n<stylechange>张万山亲自出面，在场的人都明白是怎么一回事。\n“张重山师兄，莫非你的伤好的差不多，又想继续回去修养？如果这样，师弟不客气了。”\n林飞嘴上浮起一抹笑容，露出一口洁白牙齿，轻轻踏前一步，说出一番让人无法相信的话。\n这林飞是不是吃错药了。\n先前喝斥林飞，正是伤势渐好的张重山。\n“不要过来，给我站住，不要动。”\n闻言，张重山眼中闪过一抹惧意，下意识退开一步，仅仅是一步，暴露出内心之中的害怕。\n自己输在林飞这废物手上，大哥的帮手张风浪，同样被打败，如今还躺在床上养伤，下意识对林飞产生一股惧意，连他自己都不知道。\n<stylechange>林飞不在意张重山，当见到这家伙伤势恢复的如此之快，心里不由暗暗惊讶，真不愧是有一个外门高手大哥，疗伤丹药服用下去，伤势恢复神速。\n目光一转，转向某人身上，脸上表情微微一动，一颗心沉下来。\n“这人应该就是张万山，罡气护身高手，外门弟子之中，位居前三十的存在，张重山的大哥。”\n视野之中，一位貌相和张重山相差无几的年轻人，冷如冰山，周身之内，寒气逼人，尚未接近，寒气袭来，无形之中，空出一个位置。\n林飞脑中，第一时间浮现出，关于张万山的个人信息。\n\n手机用户请到m.qidian.com阅读。\n手机阅读器、看书更方便。【<stylechange>安卓版】 <stylechange>";
    string allfont="colordefault fontdefault size1.6em bold1 italic0 underline0end<stylechange>colordefault fontdefault size63% bold0 italic0 underline0end<stylechange>colordefault fontdefault size63% bold0 italic0 underline0end<stylechange>colordefault fontdefault size63% bold0 italic0 underline0end<stylechange>colordefault fontdefault size63% bold0 italic0 underline0end<stylechange>colordefault fontdefault size63% bold0 italic0 underline0end<stylechange>colordefault fontdefault size63% bold0 italic0 underline0end<stylechange>colordefault fontdefault size63% bold0 italic0 underline0end<stylechange>colordefault fontdefault size63% bold0 italic0 underline0end<stylechange>colordefault fontdefault size63% bold0 italic0 underline0end<stylechange>colorblue fontdefault size63% bold0 italic0 underline1end<stylechange>";

    /*
     * After transfering html to two string. pass these two string to text
     * The
     */

    Text test1;
    test1.readInText(allwords1,output.getallsetting());
    Frame f(100,20,800,600,1);
    f.text(test1);
    Page pg(1000,1000,1);
    Frame f2(100,630,800,600,2);
    f2.text(test1);
    pg.addFrame(f);
    pg.addFrame(f2);
    w.addFrame(pg);
    w.show();

    return a.exec();
}
TRANS texttrans(string htmlpath1){
    /*setlocale(LC_ALL, "chs");
    ios_base::sync_with_stdio(false); // 缺少的话，wcout wchar_t 会漏掉中文
    wcout.imbue(locale(""));
    wstring u = L"奥尔as123";
    wcout << u;*/

    /*int i = 0;
    while(true){

        if(ncx[i][0]==L""&&ncx[i][1]==L"")
            break;
        else {wcout << ncx[i][0]<< endl<<ncx[i][1]<<endl;
        i++;}
    }//cout << i;*/
    //string htmlpath1 = "C:\\Users\\lenovo\\Desktop\\Little Women\\OEBPS\\bano_9781411432574_oeb_c40_r1.html";//原文件地址
    /*QString qstr = QString::fromStdString(htmlpath1);
    qstr.replace(".html",".txt");
    string htmlpath2 = qstr.toStdString();
    //string txtpath = htmlpath.replace()
    //cout << htmlpath1<<endl <<htmlpath2;
    rename(htmlpath1.c_str(),htmlpath2.c_str());*/
    wstring wsrc = wopenfile(htmlpath1);
    wstring body;
    while(true){
        int pos1 = wsrc.find(L"body>");//head of body
        if(pos1<0)
            break;
        int pos2 = wsrc.find(L"/body>",pos1+5);//tail of body
        if (pos2<0)
            break;
        body = wsrc.substr(pos1+5,pos2-pos1-6);//text of body
        wsrc.erase(wsrc.begin()+pos1,wsrc.begin()+pos2+1);
            //wcout<<body<<endl;
    }
    //wcout<<body<<endl;
    string src = openfile(htmlpath1);
    string sub;
    while(true){
        int pos1 = src.find("link");//find css head
        if(pos1<0)
            break;
        int pos2 = src.find("href=\"",pos1+4);//head of css
        if (pos2<0)
            break;
        int pos3 = src.find(".css",pos2+6);  // tail of css
        sub = src.substr(pos2+6,pos3-pos2-2);//text of body
        if(sub.find(">",pos2)>pos3)
        src.erase(src.begin()+pos1,src.begin()+pos2+1);
            //cout<<sub<<endl;
            break;
    }
    string csspath = sub;
    string csssub =openfile(csspath);
    //cout << csssub<<endl;
    string bodysetting = getsetting(csssub,"body")+"end<stylechange>";
    string h1setting = getsetting(csssub,"h1")+"end<stylechange>";
    string h2setting = getsetting(csssub,"h2")+"end<stylechange>";
    string h3setting = getsetting(csssub,"h3")+"end<stylechange>";
    string h4setting = getsetting(csssub,"h4")+"end<stylechange>";
    string h5setting = getsetting(csssub,"h5")+"end<stylechange>";
    string h6setting = getsetting(csssub,"h6")+"end<stylechange>";
    string divsetting = getsetting(csssub,"div")+"end<stylechange>";
    string asetting = getsetting(csssub,"a ")+"end<stylechange>";//lack of href
    //cout << h1setting;
    wstring stylechange = L"<stylechange>";
    wstring bodytrans = L"";
    string allsetting = "";
    wstring imgset = L"";
    int countendl = 0;
    string setbuf;
    for(int i = 0; i < body.size();i++){
        if(body[i]=='<'){
            if(body[i+1]==L'p'){
                if(body[i+2]==L'>'){
                    countendl++;
                    if(countendl%8 == 7){
                       bodytrans += L"\\n"+ stylechange;
                       allsetting += setbuf;
                    }
               else  bodytrans += L"\\n";

                }
            }
            else if(body[i+1]==L'/'){
                if(body[i+2]==L'b'){
                    if(body[i+3]==L'r'){
                        if(body[i+4]==L'/'){
                            countendl++;
                            if(countendl%8 == 7){
                               bodytrans += L"\\n"+ stylechange;
                               allsetting += setbuf;
                            }
                            else bodytrans += L"\\n";
                            }
                        }
                    }
                }
            else if(body[i+1]==L'h'){
                if(body[i+2]==L'1'){
                    bodytrans += stylechange;
                allsetting += h1setting;
                setbuf = h1setting;}
                else if(body[i+2]==L'2'){
                    bodytrans += stylechange;
                allsetting += h2setting;
                setbuf = h2setting;}
                else if(body[i+2]==L'3'){
                    bodytrans += stylechange;
                allsetting += h3setting;
                setbuf = h3setting;}
                else if(body[i+2]==L'4'){
                    bodytrans += stylechange;
                allsetting += h4setting;
                setbuf = h4setting;}
                else if(body[i+2]==L'5'){
                    bodytrans += stylechange;
                allsetting += h5setting;
                setbuf = h5setting;}
                else if(body[i+2]==L'6'){
                    bodytrans += stylechange;
                allsetting += h6setting;
                setbuf = h6setting;}
            }
            else if(body[i+1]==L'd'){
                if(body[i+2]==L'i'){
                    if(body[i+3]==L'v'){
                        bodytrans += L"\\n"+stylechange;
                        if(body.find(L"class=",i)<body.find(L">",i)){
                            int pos1 = body.find(L"class=",i);
                            int pos2 = body.find(L"\"",pos1+7);
                            wstring wclassname = body.substr(pos1+7,pos2-pos1-7);
                            string classname = "."+wtos(wclassname)+" ";
                            allsetting += getsetting(csssub,classname)+"end<stylechange>";
                            setbuf = getsetting(csssub,classname)+"end<stylechange>";
                        }
                        else if(body.find(L"style=",i)<body.find(L">",i)){
                            int pos1 = body.find(L"style=",i);
                            int pos2 = body.find(L"\"",pos1+7);
                            wstring wstyle = body.substr(pos1+7,pos2-pos1-7);
                            string style = wtos(wstyle);
                            allsetting += settingdetail(style,"div") + "end<stylechange>";
                            setbuf = settingdetail(style,"div") + "end<stylechange>";
                        }
                       else {allsetting += divsetting;
                            setbuf = divsetting;}
                    }
                }
            }
            else if(body[i+1]==L'a'){
                int pos1 = body.find(L"href=",i);
                //int pos2 = body.find(L"\"",pos1+6);
                if(body.find(L">",i)>pos1)
                {//wstring href = body.substr(pos1 + 6,pos2 - pos1 - 6);
                //cout << href;
                bodytrans += stylechange;
                allsetting += asetting;
                setbuf = asetting;}
            }
            else if(body[i+1]==L'i'){
                if(body[i+2]==L'm'){
                    if(body[i+3]==L'g'){
                        bodytrans += stylechange + L"<img>";
                        int pos1 = body.find(L"src=");
                        int pos2 = body.find(L"\"",pos1 + 5);
                        imgset = body.substr(pos1+5,pos2-pos1-5);//wcout<<imgset;
                        if(body.find(L"style=",i)<body.find(L">",i)){
                            int posstyle1 = body.find(L"style=",i);
                            int posstyle2 = body.find(L"\"",posstyle1+7);
                            imgset += body.substr(posstyle1+7,posstyle2-posstyle1-7);
                                        //wcout << imgset;
                        }
                        else if(body.find(L"class=",i)<body.find(L">",i)){
                            int posclass1 = body.find(L"class=",i);
                            int posclass2 = body.find(L"\"",posclass1+7);
                            wstring wclassname = body.substr(posclass1+7,posclass2-posclass1-7);
                            string sclassname = "."+wtos(wclassname)+" ";
                            //cout << sclassname;
                            string fullsetting;
                            if(csssub.find(sclassname)!=string::npos){
                                    int pos1 = csssub.find("{",csssub.find(sclassname));
                                    int pos2 = csssub.find("}",pos1 + 1);
                                    fullsetting = csssub.substr(pos1+1,pos2-pos1-1);
                                    string buf1;
                                    string setting = "height=";
                                    if(fullsetting.find("height")!=string::npos){
                                        int pos1 = fullsetting.find(":",fullsetting.find("height"));
                                        int pos2 = fullsetting.find(";",pos1+1);
                                        buf1 = fullsetting.substr(pos1+1,pos2-pos1-1);
                                        string buf2 = "";
                                        for(int i = 0;i<buf1.size();i++){
                                            if(buf1[i]!=' ')
                                            buf2 += buf1[i];
                                        }
                                        setting += buf2+"width=";
                                    }
                                    else
                                        setting += "100%width=";
                                    if(fullsetting.find("width")!=string::npos){
                                        int pos1 = fullsetting.find(":",fullsetting.find("width"));
                                        int pos2 = fullsetting.find(";",pos1+1);
                                        buf1 = fullsetting.substr(pos1+1,pos2-pos1-1);
                                        string buf2 = "";
                                        for(int i = 0;i<buf1.size();i++){
                                            if(buf1[i]!=' ')
                                            buf2 += buf1[i];
                                        }
                                        setting += buf2+"align=";
                                    }
                                    else
                                        setting += "100%align=";
                                    if(fullsetting.find("align")!=string::npos){
                                        int pos1 = fullsetting.find(":",fullsetting.find("align"));
                                        int pos2 = fullsetting.find(";",pos1+1);
                                        buf1 = fullsetting.substr(pos1+1,pos2-pos1-1);
                                        string buf2 = "";
                                        for(int i = 0;i<buf1.size();i++){
                                            if(buf1[i]!=' ')
                                            buf2 += buf1[i];
                                        }
                                        setting += buf2;
                                    }
                                    else
                                        setting += "middle";
                                    //cout << setting;
                                    imgset += stow(setting);
                                    //wcout << imgset;
                                }
                        }else{
                        if(body.find(L"height=",i)<body.find(L">",i)){
                            int posheight1 = body.find(L"height=",i);
                            int posheight2 = body.find(L"\"",posheight1+8);
                            imgset += body.substr(posheight1+8,posheight2-posheight1-8);
                        }else
                            imgset += L"height:100%";
                        if(body.find(L"width=",i)<body.find(L">",i)){
                            int poswidth1 = body.find(L"width=",i);
                            int poswidth2 = body.find(L"\"",poswidth1+7);
                            imgset += body.substr(poswidth1+7,poswidth2-poswidth1-7);
                        }else
                            imgset += L"width:100%";
                        if(body.find(L"align=",i)<body.find(L">",i)){
                            int posalign1 = body.find(L"align=",i);
                            int posalign2 = body.find(L"\"",posalign1+7);
                            imgset += body.substr(posalign1+7,posalign2-posalign1-7);
                        }else
                            imgset += L"align:middle";
                        }
                    }
                }
            }
            i = body.find(L'>',i);
        }
        else
        {
           bodytrans += body[i];}

    }
    bodytrans += stylechange;
    bodytrans = bodytrans.substr(14);
    //wcout <<bodytrans;
    //cout << allsetting;
    //wcout << imgset;

    QString qimgset = QString::fromStdWString(imgset);//image组要的设定，含src,heigth，width，align四要素
    TRANS output(bodytrans, allsetting, qimgset);
    //rename(htmlpath2.c_str(),htmlpath1.c_str());
    wofstream test;

    test.open("testfile.txt");
    test << bodytrans;
    test.close();
    wcout<<wopenfile("testfile.txt");
    ofstream test2;
    test2.open("testfile2.txt");
    test2 << allsetting;
    test2.close();
    wcout<<wopenfile("testfile2.txt");
    //system("pause");
    return output;
}

string getsetting(string csssub, string settingname){
    string fullsetting;
    if(csssub.find(settingname)!=string::npos){
            int pos1 = csssub.find("{",csssub.find(settingname));
            int pos2 = csssub.find("}",pos1 + 1);
            fullsetting = csssub.substr(pos1+1,pos2-pos1-1);
            //cout << fullsetting;
        }
       string setting = settingdetail(fullsetting,settingname);
       return setting;
}
string settingdetail(string fullsetting,string settingname){
    string buf1;
    string setting = "color";
    if(fullsetting.find("color")!=string::npos){
        int pos1 = fullsetting.find(":",fullsetting.find("color"));
        int pos2 = fullsetting.find(";",pos1+1);
        buf1 = fullsetting.substr(pos1+1,pos2-pos1-1);
        string buf2 = "";
        for(int i = 0;i<buf1.size();i++){
            if(buf1[i]!=' ')
            buf2 += buf1[i];
        }
        setting +=buf2 +" font";
        if(settingname == "body"){
            bodydefault.color = buf2;}
    }
    else{
        setting += bodydefault.color+" font";
    }
    if(fullsetting.find("font-family")!=string::npos){
        int pos1 = fullsetting.find(":",fullsetting.find("font-family"));
        int pos2 = fullsetting.find(";",pos1+1);
        buf1 = fullsetting.substr(pos1+1,pos2-pos1-1);
        string buf2 = "";
        for(int i = 0;i<buf1.size();i++){
            if(buf1[i]!=' ')
            buf2 += buf1[i];
        }
        setting +=buf2 +" size";
        if(settingname == "body"){
            bodydefault.font = buf2;}
    }
    else{
        setting += bodydefault.font+" size";
    }if(fullsetting.find("font-size")!=string::npos){
        int pos1 = fullsetting.find(":",fullsetting.find("font-size"));
        int pos2 = fullsetting.find(";",pos1+1);
        buf1 = fullsetting.substr(pos1+1,pos2-pos1-1);
        string buf2 = "";
        for(int i = 0;i<buf1.size();i++){
            if(buf1[i]!=' ')
            buf2 += buf1[i];
        }
        setting +=buf2 +" bold";
        if(settingname == "body"){
            bodydefault.size = buf2;}
    }
    else{
        setting += bodydefault.size+" bold";
    }if(fullsetting.find("bold")!=string::npos){
        setting += "1 italic";
        if(settingname == "body"){
            bodydefault.bold = "1";}
    }
    else{
        setting += bodydefault.bold+" italic";
    }if(fullsetting.find("italic")!=string::npos){
        setting += "1 underline";
        if(settingname == "body"){
            bodydefault.italic = "1";}
    }
    else{
        setting += bodydefault.italic+" underline";
    }if(fullsetting.find("underline")!=string::npos){
        setting += "1";
        if(settingname == "body"){
            bodydefault.underline = "1";}
    }
    else{
        setting += bodydefault.underline;
    }


return setting;
}


