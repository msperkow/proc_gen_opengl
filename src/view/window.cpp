#include <iostream>
#include "view/window.hpp"

Window::Window(std::string title, int posX, int posY, int height, int width)
: title(title), open(true)
{
	assert(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER) == 0);

	// GL 3.3 + GLSL 130
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	// Create sdlWindow with graphics context
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
	SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_OPENGL
	| SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
	sdlWindow = SDL_CreateWindow(title.c_str(), posX, posY, width, height, window_flags);
	if (sdlWindow == NULL)
	{
		std::cerr << "Failed to create a window" << std::endl;
	}
	glContext = SDL_GL_CreateContext(sdlWindow);
	SDL_GL_MakeCurrent(sdlWindow, glContext);
	SDL_GL_SetSwapInterval(1); // Enable vsync

	GLenum status = glewInit();
	if (status != GLEW_OK)
	{
		std::cerr << "Glew failed to initialize" << std::endl;
	}

	glEnable(GL_DEPTH_TEST);

	setupImGui();
}

Window::~Window()
{
	closeImGui();
	SDL_GL_DeleteContext(glContext);
	SDL_DestroyWindow(sdlWindow);
	SDL_Quit();
}

void Window::setupImGui()
{
	const char* glsl_version = "#version 330";
	// Initialize OpenGL loader
	IM_ASSERT(glewInit() == GLEW_OK);

	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	io = &ImGui::GetIO();

	// Setup Platform/Renderer bindings
	ImGui_ImplSDL2_InitForOpenGL(sdlWindow, glContext);
	ImGui_ImplOpenGL3_Init(glsl_version);

	// Setup Dear ImGui style
	ImGui::StyleColorsDark();
	//ImGui::StyleColorsClassic();
}

void Window::closeImGui()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();
}

bool Window::isOpen()
{
	return open;
}

void Window::setClose()
{
	open = false;
}

SDL_Window *Window::getSDLWindow()
{
	return sdlWindow;
}

void Window::render()
{
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	SDL_GL_SwapWindow(sdlWindow);
}

void Window::updateViewportAndClear()
{
	//todo should this be here or in View?
	glViewport(0, 0, (int)io->DisplaySize.x, (int)io->DisplaySize.y);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//todo temporary
	glClearColor(.58f, .78f, .89f, 1.f);
}

int Window::getWidth() const
{
	int w;
	SDL_GetWindowSize(sdlWindow, &w, nullptr);
	return w;
}

int Window::getHeight() const
{
	int h;
	SDL_GetWindowSize(sdlWindow, nullptr, &h);
	return h;
}

void Window::setFullScreenWindowed()
{
	SDL_SetWindowFullscreen(sdlWindow, 0);
}

void Window::setFullScreenBorderless()
{
	SDL_SetWindowFullscreen(sdlWindow, SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_WINDOW_BORDERLESS);
}

void Window::setFullScreen()
{
	SDL_SetWindowFullscreen(sdlWindow, SDL_WINDOW_FULLSCREEN);
}

void Window::maximize()
{
	SDL_MaximizeWindow(sdlWindow);
}

void Window::minimize()
{
	SDL_MinimizeWindow(sdlWindow);
}
