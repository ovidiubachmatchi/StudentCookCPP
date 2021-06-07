#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ingredient.h"
#include <string.h>
#include <vector>
#include <utility>
#include <QGroupBox>
#include <QListWidget>

QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("StudentCook");
    ui->input->setPlaceholderText("Add an ingredient");
    /*
    if (ui->input->text().isEmpty())
        ui->no_ingredients->hide();
    else
        ui->no_ingredients->show();
    */

    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("");
    db.setDatabaseName("authentication_system");
    db.open();

    QStringList ingredients;
    ingredients<<"butter"<<"egg"<<"milk"<<"parmesan"<<"cheddar"<<"american cheese"<<"sour cream"<<"cream cheese"<<"mozzarella"<<"yogurt"<<"cream"<<"evaporated milk"<<"whipped cream"<<"half and half"<<"feta"<<"monterey jack cheese"<<"condensed milk"<<"cottage cheese"<<"ice cream"<<"swiss cheese"<<"velveeta"<<"frosting"<<"buttermilk"<<"ricotta"<<"goat cheese"<<"provolone"<<"blue cheese"<<"powdered milk"<<"colby cheese"<<"pepper jack"<<"italian cheese"<<"soft cheese"<<"gouda"<<"pepperjack cheese"<<"romano"<<"brie"<<"pizza cheese"<<"ghee"<<"creme fraiche"<<"cheese soup"<<"gruyere"<<"pecorino cheese"<<"custard"<<"muenster"<<"queso fresco cheese"<<"hard cheese"<<"havarti cheese"<<"asiago"<<"mascarpone"<<"neufchatel"<<"halloumi"<<"paneer"<<"brick cheese"<<"camembert cheese"<<"goat milk"<<"garlic herb cheese"<<"edam cheese"<<"manchego"<<"fontina"<<"stilton cheese"<<"emmenthaler cheese"<<"red leicester cheese"<<"jarlsberg cheese"<<"bocconcini cheese"<<"farmer cheese"<<"creme de cassis"<<"wensleydale cheese"<<"longhorn cheese"<<"double gloucester cheese"<<"raclette cheese"<<"lancashire cheese"<<"cheshirecheese"<<"onion"<<"garlic"<<"tomato"<<"lettuce"<<"potato"<<"carrot"<<"bell pepper"<<"basil"<<"parsley"<<"broccoli"<<"corn"<<"spinach"<<"mushroom"<<"green beans"<<"ginger"<<"chili pepper"<<"celery"<<"rosemary"<<"salad greens"<<"red onion"<<"cucumber"<<"sweet potato"<<"pickle"<<"avocado"<<"zucchini"<<"cilantro"<<"frozen vegetables"<<"olive"<<"asparagus"<<"cabbage"<<"cauliflower"<<"dill"<<"kale"<<"mixed vegetable"<<"pumpkin"<<"squash"<<"mint"<<"scallion"<<"sun dried tomato"<<"shallot"<<"eggplant"<<"beet"<<"butternut squash"<<"horseradish"<<"leek"<<"caper"<<"brussels sprout"<<"artichoke heart"<<"chia seeds"<<"radish"<<"sauerkraut"<<"artichoke"<<"portobello mushroom"<<"sweet pepper"<<"arugula"<<"spaghetti squash"<<"capsicum"<<"bok choy"<<"parsnip"<<"okra"<<"yam"<<"fennel"<<"turnip"<<"snow peas"<<"bean sprouts"<<"seaweed"<<"chard"<<"collard"<<"canned tomato"<<"pimiento"<<"watercress"<<"tomatillo"<<"rocket"<<"mustard greens"<<"bamboo shoot"<<"rutabaga"<<"endive"<<"broccoli rabe"<<"jicama"<<"kohlrabi"<<"hearts of palm"<<"butternut"<<"celery root"<<"daikon"<<"radicchio"<<"porcini"<<"chinese broccoli"<<"jerusalem artichoke"<<"cress"<<"water chestnut"<<"dulse"<<"micro greens"<<"burdock"<<"chayote"<<"lemon"<<"apple"<<"banana"<<"lime"<<"strawberry"<<"orange"<<"pineapple"<<"blueberry"<<"raisin"<<"coconut"<<"grape"<<"peach"<<"raspberry"<<"cranberry"<<"mango"<<"pear"<<"blackberry"<<"cherry"<<"date"<<"watermelon"<<"berries"<<"kiwi"<<"grapefruit"<<"mandarin"<<"craisins"<<"cantaloupe"<<"plum"<<"apricot"<<"clementine"<<"prunes"<<"apple butter"<<"pomegranate"<<"nectarine"<<"fig"<<"tangerine"<<"papaya"<<"rhubarb"<<"sultanas"<<"plantain"<<"currant"<<"passion fruit"<<"guava"<<"persimmons"<<"lychee"<<"lingonberry"<<"tangelos"<<"kumquat"<<"boysenberry"<<"star fruit"<<"quince"<<"honeydew"<<"crabapples"<<"rice"<<"pasta"<<"flour"<<"bread"<<"baking powder"<<"baking soda"<<"bread crumbs"<<"cornstarch"<<"rolled oats"<<"noodle"<<"flour tortillas"<<"pancake mix"<<"yeast"<<"cracker"<<"quinoa"<<"brown rice"<<"cornmeal"<<"self rising flour"<<"cake mix"<<"saltines"<<"popcorn"<<"macaroni cheese mix"<<"corn tortillas"<<"ramen"<<"cereal"<<"biscuits"<<"stuffing mix"<<"couscous"<<"pie crust"<<"bisquick"<<"chips"<<"angel hair"<<"coconut flake"<<"bread flour"<<"croutons"<<"lasagne"<<"pizza dough"<<"bagel"<<"puff pastry"<<"hot dog bun"<<"barley"<<"multigrain bread"<<"potato flakes"<<"pretzel"<<"cornbread"<<"english muffin"<<"cornflour"<<"crescent roll dough"<<"cream of wheat"<<"coconut flour"<<"pita"<<"risotto"<<"muffin mix"<<"bicarbonate of soda"<<"ravioli"<<"wheat"<<"rice flour"<<"polenta"<<"baguette"<<"gnocchi"<<"vermicelli"<<"semolina"<<"wheat germ"<<"buckwheat"<<"croissants"<<"bread dough"<<"filo dough"<<"yeast flake"<<"pierogi"<<"matzo meal"<<"rye"<<"tapioca flour"<<"shortcrust pastry"<<"potato starch"<<"breadsticks"<<"ciabatta"<<"spelt"<<"angel food"<<"tapioca starch"<<"starch"<<"whole wheat flour"<<"gram flour"<<"sourdough starter"<<"wafer"<<"bran"<<"challah"<<"sponge cake"<<"malt extract"<<"sorghum flour"<<"sugar"<<"brown sugar"<<"honey"<<"confectioners sugar"<<"maple syrup"<<"corn syrup"<<"molasses"<<"artificial sweetener"<<"agave nectar"<<"cinnamon"<<"vanilla"<<"garlic powder"<<"paprika"<<"oregano"<<"chili powder"<<"red pepper flake"<<"cumin"<<"cayenne"<<"italian seasoning"<<"thyme"<<"onion powder"<<"nutmeg"<<"ground nutmeg"<<"curry powder"<<"bay leaf"<<"taco seasoning"<<"sage"<<"clove"<<"allspice"<<"turmeric"<<"chive"<<"peppercorn"<<"ground coriander"<<"cajun seasoning"<<"coriander"<<"celery salt"<<"vanilla essence"<<"herbs"<<"steak seasoning"<<"poultry seasoning"<<"chile powder"<<"cardamom"<<"italian herbs"<<"tarragon"<<"garam masala"<<"marjoram"<<"mustard seed"<<"celery seed"<<"chinese five spice"<<"italian spice"<<"saffron"<<"onion flake"<<"herbes de provence"<<"chipotle"<<"dill seed"<<"fennel seed"<<"caraway"<<"cacao"<<"star anise"<<"savory"<<"chili paste"<<"tamarind"<<"aniseed"<<"fenugreek"<<"lavender"<<"old bay seasoning"<<"lemon balm"<<"chicken breast"<<"ground beef"<<"bacon"<<"sausage"<<"beef steak"<<"ham"<<"hot dog"<<"pork chops"<<"chicken thighs"<<"ground turkey"<<"cooked chicken"<<"turkey"<<"pork"<<"pepperoni"<<"whole chicken"<<"chicken leg"<<"ground pork"<<"chorizo"<<"chicken wings"<<"beef roast"<<"polish sausage"<<"salami"<<"pork roast"<<"ground chicken"<<"pork ribs"<<"spam"<<"venison"<<"pork shoulder"<<"bologna"<<"bratwurst"<<"prosciutto"<<"lamb"<<"corned beef"<<"chicken roast"<<"lamb chops"<<"pancetta"<<"ground lamb"<<"beef ribs"<<"duck"<<"pork belly"<<"beef liver"<<"leg of lamb"<<"canadian bacon"<<"beef shank"<<"veal"<<"chicken giblets"<<"cornish hen"<<"lamb shoulder"<<"lamb shank"<<"deer"<<"ground veal"<<"pastrami"<<"rabbit"<<"sliced turkey"<<"pork loin"<<"elk"<<"beef suet"<<"veal cutlet"<<"lamb loin"<<"marrow bones"<<"goose"<<"chicken tenders"<<"veal chops"<<"quail"<<"oxtail"<<"pheasant"<<"lamb liver"<<"moose"<<"turkey liver"<<"pork liver"<<"veal shank"<<"foie gras"<<"beef sirloin"<<"liver sausage"<<"sweetbread"<<"wild boar"<<"snail"<<"pigeon"<<"duck liver"<<"goose liver"<<"grouse"<<"ostrich"<<"soppressata"<<"alligator"<<"canned tuna"<<"salmon"<<"tilapia"<<"fish fillets"<<"cod"<<"canned salmon"<<"anchovy"<<"smoked salmon"<<"sardines"<<"tuna steak"<<"whitefish"<<"halibut"<<"trout"<<"haddock"<<"flounder"<<"catfish"<<"mahi mahi"<<"mackerel"<<"sole"<<"sea bass"<<"red snapper"<<"swordfish"<<"pollock"<<"herring"<<"perch"<<"grouper"<<"caviar"<<"monkfish"<<"rockfish"<<"lemon sole"<<"pike"<<"barramundi"<<"eel"<<"bluefish"<<"carp"<<"cuttlefish"<<"pompano"<<"arctic char"<<"john dory"<<"marlin"<<"amberjack"<<"sturgeon"<<"shrimp"<<"crab"<<"prawns"<<"scallop"<<"clam"<<"lobster"<<"mussel"<<"oyster"<<"squid"<<"calamari"<<"crawfish"<<"octopus"<<"cockle"<<"conch"<<"sea urchin"<<"mayonnaise"<<"ketchup"<<"mustard"<<"vinegar"<<"soy sauce"<<"balsamic vinegar"<<"worcestershire"<<"hot sauce"<<"barbecue sauce"<<"ranch dressing"<<"wine vinegar"<<"apple cider vinegar"<<"cider vinegar"<<"italian dressing"<<"rice vinegar"<<"salad dressing"<<"tabasco"<<"fish sauce"<<"teriyaki"<<"steak sauce"<<"tahini"<<"enchilada sauce"<<"vinaigrette dressing"<<"oyster sauce"<<"honey mustard"<<"sriracha"<<"caesar dressing"<<"taco sauce"<<"mirin"<<"blue cheese dressing"<<"sweet and sour sauce"<<"thousand island"<<"picante sauce"<<"buffalo sauce"<<"french dressing"<<"tartar sauce"<<"cocktail sauce"<<"marsala"<<"adobo sauce"<<"tzatziki sauce"<<"sesame dressing"<<"ponzu"<<"duck sauce"<<"pickapeppa sauce"<<"yuzu juice"<<"cream sauce"<<"olive oil"<<"vegetable oil"<<"cooking spray"<<"canola oil"<<"shortening"<<"sesame oil"<<"coconut oil"<<"peanut oil"<<"sunflower oil"<<"lard"<<"grape seed oil"<<"corn oil"<<"almond oil"<<"avocado oil"<<"safflower oil"<<"walnut oil"<<"hazelnut oil"<<"palm oil"<<"soybean oil"<<"mustard oil"<<"pistachio oil"<<"soya oil"<<"bouillon"<<"ground ginger"<<"sesame seed"<<"cream of tartar"<<"chili sauce"<<"soya sauce"<<"apple cider"<<"hoisin sauce"<<"liquid smoke"<<"rice wine"<<"vegetable bouillon"<<"poppy seed"<<"balsamic glaze"<<"miso"<<"wasabi"<<"fish stock"<<"rose water"<<"pickling salt"<<"champagne vinegar"<<"bbq rub"<<"jamaican jerk spice"<<"accent seasoning"<<"pickling spice"<<"mustard powder"<<"mango powder"<<"adobo seasoning"<<"kasuri methi"<<"caribbean jerk seasoning"<<"brine"<<"matcha powder"<<"cassia"<<"tomato sauce"<<"tomato paste"<<"salsa"<<"pesto"<<"alfredo sauce"<<"beef gravy"<<"curry paste"<<"chicken gravy"<<"cranberry sauce"<<"turkey gravy"<<"mushroom gravy"<<"sausage gravy"<<"onion gravy"<<"cream gravy"<<"pork gravy"<<"tomato gravy"<<"giblet gravy"<<"tofu"<<"green beans"<<"peas"<<"black beans"<<"chickpea"<<"lentil"<<"refried beans"<<"hummus"<<"chili beans"<<"lima beans"<<"kidney beans"<<"pinto beans"<<"edamame"<<"split peas"<<"snap peas"<<"soybeans"<<"cannellini beans"<<"navy beans"<<"french beans"<<"red beans"<<"great northern beans"<<"fava beans"<<"white wine"<<"beer"<<"red wine"<<"vodka"<<"rum"<<"whiskey"<<"tequila"<<"sherry"<<"bourbon"<<"cooking wine"<<"whisky"<<"liqueur"<<"brandy"<<"gin"<<"kahlua"<<"irish cream"<<"triple sec"<<"champagne"<<"amaretto"<<"cabernet sauvignon"<<"vermouth"<<"bitters"<<"maraschino"<<"sake"<<"grand marnier"<<"masala"<<"dessert wine"<<"schnapps"<<"port wine"<<"sparkling wine"<<"cognac"<<"chocolate liqueur"<<"burgundy wine"<<"limoncello"<<"creme de menthe"<<"bloody mary"<<"raspberry liquor"<<"curacao"<<"frangelico"<<"shaoxing wine"<<"absinthe"<<"madeira wine"<<"ouzo"<<"anisette"<<"grappa"<<"ciclon"<<"drambuie"<<"chicken broth"<<"mushroom soup"<<"beef broth"<<"tomato soup"<<"vegetable stock"<<"chicken soup"<<"onion soup"<<"vegetable soup"<<"celery soup"<<"dashi"<<"lamb stock"<<"pork stock"<<"veal stock"<<"peanut butter"<<"almond"<<"walnut"<<"pecan"<<"peanut"<<"cashew"<<"flax"<<"pine nut"<<"pistachio"<<"almond meal"<<"hazelnut"<<"macadamia"<<"almond paste"<<"chestnut"<<"praline"<<"macaroon"<<"margarine"<<"coconut milk"<<"almond milk"<<"soy milk"<<"rice milk"<<"hemp milk"<<"non dairy creamer"<<"chocolate"<<"apple sauce"<<"strawberry jam"<<"graham cracker"<<"marshmallow"<<"chocolate syrup"<<"potato chips"<<"nutella"<<"chocolate morsels"<<"bittersweet chocolate"<<"pudding mix"<<"raspberry jam"<<"dark chocolate"<<"chocolate chips"<<"jam"<<"white chocolate"<<"brownie mix"<<"chocolate pudding"<<"jello"<<"caramel"<<"chocolate powder"<<"candy"<<"corn chips"<<"cookies"<<"apricot jam"<<"chocolate bar"<<"cookie dough"<<"oreo"<<"doritos"<<"chocolate cookies"<<"butterscotch"<<"blackberry preserves"<<"blueberry jam"<<"peach preserves"<<"cherry jam"<<"fig jam"<<"plum jam"<<"cinnamon roll"<<"fudge"<<"cookie crumb"<<"grape jelly"<<"chilli jam"<<"lady fingers"<<"black pudding"<<"chocolate wafer"<<"gummy worms"<<"biscotti biscuit"<<"doughnut"<<"amaretti cookies"<<"apple jelly"<<"red pepper jelly"<<"orange jelly"<<"jalapeno jelly"<<"mint jelly"<<"currant jelly"<<"lemon jelly"<<"quince jelly"<<"coffee"<<"orange juice"<<"tea"<<"green tea"<<"apple juice"<<"tomato juice"<<"coke"<<"chocolate milk"<<"pineapple juice"<<"lemonade"<<"cranberry juice"<<"espresso"<<"fruit juice"<<"ginger ale"<<"club soda"<<"sprite"<<"kool aid"<<"grenadine"<<"margarita mix"<<"cherry juice"<<"pepsi"<<"mountain dew";

    QCompleter *completer = new QCompleter(ingredients, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    //completer->event();
    ui->input->setCompleter(completer);

    connect(ui->add_ingredient, &QPushButton::released, this, &MainWindow::add_ingredient);
    connect(ui->delete_ingredient, &QPushButton::released, this, &MainWindow::delete_ingredient);
    connect(ui->clear, &QPushButton::released, this, &MainWindow::clear);
    connect(ui->show_recipes, &QPushButton::released, this, &MainWindow::show_recipes);
}
void RemoveLayout (QWidget* widget)
{
    QLayout* layout = widget->layout ();
    if (layout != 0)
    {
    QLayoutItem *item;
    while ((item = layout->takeAt(0)) != 0)
        layout->removeItem (item);
    delete layout;
    }
}
void MainWindow::show_recipes()
{

//    QNetworkAccessManager *nam = new QNetworkAccessManager(this);
//    connect(nam, &QNetworkAccessManager::finished, this, &MainWindow::downloadFinished);
//    const QUrl url = QUrl("recipe-name");
//    QNetworkRequest request(url);
//    nam->get(request);

    QSqlQuery query;
    query.exec("SELECT * FROM recipes;");
    qApp->setStyleSheet("QLineEdit { color: white; text-decoration=none; }");
    vector<pair<float,short int>> ids_procent;

    while(query.next()){
        short int id = query.value(0).toInt();
        string ingredients = query.value(2).toString().toUtf8().constData();
        float procent;
        string it_uses = list_of_ingredients.ingredients_match(ingredients,procent);
        if (procent > 1)
        ids_procent.push_back(make_pair(((float)((int)(procent * 10))) / 10,id));
    }
    sort(ids_procent.rbegin(), ids_procent.rend());

    QVBoxLayout *layout = new QVBoxLayout( );
    for(auto i:ids_procent) {
    query.prepare("SELECT * FROM recipes WHERE id_recipe=(:id);");
    query.bindValue(0, i.second);
    query.exec();

    if (query.next()) {
        string name = query.value(1).toString().toUtf8().constData();
        string ingredients = query.value(2).toString().toUtf8().constData();
        string link = query.value(3).toString().toUtf8().constData();
        string image_link = query.value(4).toString().toUtf8().constData();

        QString recipe_info = "<a href='"+ QString::fromStdString(link) + "'>" + QString::fromStdString(std::to_string(int(i.first)) + "%" + '\n' + name) + "</a>";
        QLabel *recipe_text = new QLabel;

        recipe_text->setText( recipe_info );
        recipe_text->setAlignment(Qt::AlignHCenter);
        recipe_text->setFixedHeight(100);
        recipe_text->setTextInteractionFlags(Qt::TextBrowserInteraction);
        recipe_text->setOpenExternalLinks(true);
        layout->addWidget( recipe_text );
        }
    }
    QWidget *wid=new QWidget;
    wid->setLayout(layout);
    ui->recipes->setWidgetResizable(true);
    ui->recipes->setWidget(wid);
    RemoveLayout(ui->recipes->widget());
    qApp->setStyleSheet("QLineEdit { color: white; text-decoration=none; }");
}
//void MainWindow::downloadFinished(QNetworkReply *reply)
//{
//    QPixmap pm;
//    pm.loadFromData(reply->readAll());
//    ui->recipe_picture->setPixmap(pm);
//    ui->recipe_name->setText("<a href='link'>name</a>");
//    ui->recipe_name->setOpenExternalLinks(true);
//}
void MainWindow::add_ingredient()
{
    if (ui->input->text() != "") {
    QString ingredient = ui->input->text();
    std::string utf8_text = ingredient.toUtf8().constData();
    list_of_ingredients.add(utf8_text);

    std::string ingredients_to_show = list_of_ingredients.get("\n");

    QString list_ingredients = QString::fromUtf8(ingredients_to_show);
    ui->ingredients->setText(list_ingredients);
    }
}
void MainWindow::delete_ingredient()
{
    if (ui->input->text() != "") {
    QString ingredient = ui->input->text();
    std::string utf8_text = ingredient.toUtf8().constData();
    list_of_ingredients.remove(utf8_text);

    std::string ingredients_to_show = list_of_ingredients.get("\n");

    QString list_ingredients = QString::fromUtf8(ingredients_to_show);
    ui->ingredients->setText(list_ingredients);
    if (list_ingredients == "") { ui->ingredients->setText("There are no ingredients"); }
    }

}
void MainWindow::clear()
{
    list_of_ingredients.clear();
    ui->ingredients->setText("There are no ingredients");
    ui->input->setText("");
}
MainWindow::~MainWindow()
{
    db.close();
    delete ui;
}
