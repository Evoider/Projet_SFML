#include "SettingsState.h"


void SettingsState::initVariables()
{
	this->modes = sf::VideoMode::getFullscreenModes();
} 

void SettingsState::initKeyBinds()
{

	std::ifstream ifs("Config/SettingsState_keybinds.ini");
	if (ifs.is_open())
	{
		std::string key = "";
		std::string key_name = "";

		while (ifs >> key >> key_name)
		{
			this->keyBinds[key] = this->supportedKeys->at(key_name);
		}
	}

	ifs.close();

	this->keyBinds["CLOSE"] = this->supportedKeys->at("Escape");
}

void SettingsState::initGui()
{
	
	this->buttons["APPLY"] = new gui::Button((this->window->getSize().x / 2) - 100 * this->scale, (this->window->getSize().y / 2) + 300 * this->scale, 200 * this->scale, 50 * this->scale,
		this->font, "Apply", 20 * this->scale,
		sf::Color(70, 70, 70, 200),
		sf::Color(150, 150, 150, 255),
		sf::Color(20, 20, 20, 200),
		sf::Color(0, 0, 235, 255), 2 * this->scale
	);
	this->buttons["EXIT_STATE"] = new gui::Button((this->window->getSize().x / 2) - 100 * this->scale, (this->window->getSize().y / 2) + 400 * this->scale, 200 * this->scale, 50 * this->scale,
		this->font, "Back", 20 * this->scale,
		sf::Color(70, 70, 70, 200),
		sf::Color(150, 150, 150, 255),
		sf::Color(20, 20, 20, 200),
		sf::Color(0, 0, 235, 255), 2 * this->scale
	);

	std::vector<std::string> modes_str;
	int id = 0;
	for (auto &i : this->modes)
	{
		modes_str.push_back(std::to_string(i.width) + 'x' + std::to_string(i.height));
		if (i.width == this->window->getSize().x && i.height == this->window->getSize().y)
		{
			this->defResolution = id;
		}
		id++;
	}

	//Init resolution settings
	
	std::cout << "modes_str" << modes_str.size() << "\n";

	this->ddl["RESOLUTIONS"] = new gui::DropDownList("Résolution : ",
		(this->window->getSize().x / 2) + 100 * this->scale, (this->window->getSize().y / 2) - 400 * this->scale,
		200 * this->scale, 30 * this->scale,
		&this->font, modes_str.data(), 15 * this->scale,
		sf::Color(0, 0, 235, 255), 2 * this->scale,
		modes_str.size(), this->defResolution);

	//Init Fullscreen settings
	std::string fullscreen[] = { "No","Yes" };
	if (this->graphSettings.fullscreen)
		this->defFullscreen = 1;
	else
		this->defFullscreen = 0;

	this->ddl["FULLSCREEN"] = new gui::DropDownList("FullScreen : ", (this->window->getSize().x / 2) + 100 * this->scale, (this->window->getSize().y / 2) - 300 * this->scale,
		200 * this->scale, 30 * this->scale,
		&this->font, fullscreen, 20 * this->scale, 
		sf::Color(0, 0, 235, 255), 2 * this->scale,
		2, this->defFullscreen);

	//Init v-sync settings
	std::string vsync[] = { "No","Yes" };
	if (this->graphSettings.verticaleSync)
		this->defVsync = 1;
	else
		this->defVsync = 0;

	this->ddl["V-SYNC"] = new gui::DropDownList("V-sync : ", (this->window->getSize().x / 2) + 100 * this->scale, (this->window->getSize().y / 2) - 200 * this->scale,
		200 * this->scale, 30 * this->scale,
		&this->font, vsync, 20 * this->scale,
		sf::Color(0, 0, 235, 255), 2 * this->scale,
		2, this->defVsync);

	//Init framerate settings
	std::string frameratelimitText[] = { "30","60","120","144" };
	switch (this->graphSettings.frameRateLimit)
	{
	case 30 :
		this->defFrameRateLimit = 0;
		break;
	case 60:
		this->defFrameRateLimit = 1;
		break;
	case 120:
		this->defFrameRateLimit = 2;
		break;
	case 144:
		this->defFrameRateLimit = 3;
		break;
	default:
		break;
	}

	this->ddl["FRAMERATELIMIT"] = new gui::DropDownList("Framerate limit : ", (this->window->getSize().x / 2) + 100 * this->scale, (this->window->getSize().y / 2) - 100 * this->scale,
		200 * this->scale, 30 * this->scale,
		&this->font, frameratelimitText, 20 * this->scale,
		sf::Color(0, 0, 235, 255), 2 * this->scale,
		4, this->defFrameRateLimit);

	//Init anti-aliasing settings
	std::string antialiasing[] = { "No","Yes" };
	if (this->graphSettings.contextSettings.antialiasingLevel)
		this->defAntiAlias = 1;
	else
		this->defAntiAlias = 0;

	this->ddl["ANTI-ALIASING"] = new gui::DropDownList("Antialiasing : ", (this->window->getSize().x / 2) + 100 * this->scale, (this->window->getSize().y / 2) - 0 * this->scale,
		200 * this->scale, 30 * this->scale,
		&this->font, antialiasing, 20 * this->scale,
		sf::Color(0, 0, 235, 255), 2 * this->scale,
		2, this->defAntiAlias);


}

void SettingsState::initBackground()
{
	this->textureBg.loadFromFile("Ressources/Sprites/Bg4.png");
	std::cout << this->textureBg.getSize().x << "\n";

	float scalebg = this->window->getSize().x / (float)(this->textureBg.getSize().x);
	this->background.setTexture(textureBg);
	this->background.setScale(scalebg, scalebg);
}



SettingsState::SettingsState(sf::RenderWindow* window, GraphicsSettings& graphSettings, std::map<std::string, int>* supportedKeys, std::stack<State*>* states, sf::Font font, float scale)
	:State(window, supportedKeys, states),scale(scale),font(font),graphSettings(graphSettings)
{
	this->initVariables();
	this->initKeyBinds();
	this->initBackground();
	this->initGui();
}

SettingsState::~SettingsState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
	auto it2 = this->ddl.begin();
	for (it2 = this->ddl.begin(); it2 != this->ddl.end(); ++it2)
	{
		delete it2->second;
	}
}

//Functions

void SettingsState::endState()
{
	this->quit = true;
	
	std::cout << "Ending settings state" << states->size() << "\n";
}

void SettingsState::updateWindow(sf::RenderWindow* window)
{
	this->window = window;
	this->scale = this->window->getSize().x / 1920.f;
	this->initVariables();
	this->initKeyBinds();
	this->initBackground();
	this->initGui();
}

void SettingsState::updateInput(const float& dt)
{


	//Check for key pressed

}

void SettingsState::updateGui(const float& dt)
{
	//Update buttons==============
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}

	/*Action of the Button*/

	//Apply the settings
	if (this->buttons["APPLY"]->isPressed())
	{
		this->graphSettings.resolution = this->modes[this->ddl["RESOLUTIONS"]->getSelectedId()];

		this->graphSettings.fullscreen = this->ddl["FULLSCREEN"]->getSelectedId();

		this->graphSettings.verticaleSync = this->ddl["V-SYNC"]->getSelectedId();

		switch (this->ddl["FRAMERATELIMIT"]->getSelectedId())
		{
		case 0:
			this->graphSettings.frameRateLimit = 30;
			break;
		case 1:
			this->graphSettings.frameRateLimit = 60;
			break;
		case 2:
			this->graphSettings.frameRateLimit = 120;
			break;
		case 3:
			this->graphSettings.frameRateLimit = 144;
			break;
		default:
			break;
		}

		this->graphSettings.contextSettings.antialiasingLevel =this->ddl["ANTI-ALIASING"]->getSelectedId();

		this->graphSettings.saveToFile("Config/graphics.ini");
		this->graphSettings.changed = true;
		/*this->window->create(this->graphSettings.resolution, this->graphSettings.title, sf::Style::Default);*/
	}
	
	//Exit the settings
	if (this->buttons["EXIT_STATE"]->isPressed())
	{
		this->endState();
	}

	//update Drop down lists================
	for (auto& it : this->ddl)
	{
		it.second->update(this->mousePosView,dt);
	}
}

void SettingsState::update(const float& dt)
{

	this->quit = false;
	this->updateMousePosition();
	this->updateInput(dt);
	this->updateGui(dt);


}

void SettingsState::renderGui(sf::RenderTarget* target)
{
	//Render Buttons============
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
	//Render Drop down lists=========
	for (auto& it : this->ddl)
	{
		it.second->render(target);
	}
}

void SettingsState::render(sf::RenderTarget* target)
{
	if (!target)
	{
		target = this->window;
	}
	target->draw(this->background);
	this->renderGui(target);
}

