/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	brd(gfx),
	rng(std::random_device()()),
	snek({2, 2}),
	goal(rng, snek, brd)
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{

	if (gameIsStarted)
	{
		if (!gameIsOver)
		{
			if (wnd.kbd.KeyIsPressed(VK_UP))
			{
				delta_loc = { 0, -1 };
			}
			if (wnd.kbd.KeyIsPressed(VK_DOWN))
			{
				delta_loc = { 0, 1 };
			}
			if (wnd.kbd.KeyIsPressed(VK_LEFT))
			{
				delta_loc = { -1, 0 };
			}
			if (wnd.kbd.KeyIsPressed(VK_RIGHT))
			{
				delta_loc = { 1, 0 };
			}


			snekMoveCounter++;
			if (snekMoveCounter >= snekMovePeriod)
			{
				snekMoveCounter = 0;
							
				
				const Location next = snek.getNextHeadLocation(delta_loc);

				bool colliding = snek.isInTileWithoutEnd(next);

				bool eating = next == goal.getLocation();

				if (!brd.isInBoard(next) ||
					colliding)
				{
					gameIsOver = true;
				}
				else
				{
					if (eating)
					{
						goal.respawn(rng, snek, brd);
						snek.grow();
					}

					snek.moveBy(delta_loc);
				}

			}
			snekSpeedUpCounter++;
			if (snekSpeedUpCounter >= snekSpeedUpPeriod)
			{
				snekSpeedUpCounter = 0;
				snekMovePeriod--;
			}

		}
	}
	else
	{
		gameIsStarted = wnd.kbd.KeyIsPressed(VK_RETURN);
	}

}

void Game::ComposeFrame()
{
	if (gameIsStarted)
	{
		if (!gameIsOver)
		{
			brd.drawBorder();
			snek.draw(brd);
			goal.draw(brd);
		}
		else
		{
			SpriteCodex::DrawGameOver(200, 200, gfx);
		}
	}
	else
	{
		SpriteCodex::DrawTitle(200, 200, gfx);
	}

}
