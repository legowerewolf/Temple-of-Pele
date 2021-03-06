#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>

#include "CppUnitTest.h"
#include "TestNode.hpp"

#include "../../Game/src/Helpers.h"
#include "../../Game/src/enums.h"

#include "../../Game/src/Player.h"
#include "../../Game/src/UpdateList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests {
	TEST_CLASS(Helpers) {
public:

	TEST_METHOD(oneof_positive) {
		Assert::IsTrue(oneof(1, 3, 1, 2, 3));
		Assert::IsTrue(oneof(2, 5, 1, 2, 3, 4, 5));
		Assert::IsTrue(oneof(North, 3, Northeast, North, Southeast));
	}

	TEST_METHOD(oneof_negative) {
		Assert::IsFalse(oneof(1, 3, 2, 3, 4));
		Assert::IsFalse(oneof(North, 3, Northeast, East, Southeast));
	}

	TEST_METHOD(angleCalc) {
		Assert::AreEqual(angleTo(sf::Vector2f(0, 0), sf::Vector2f(5, 0)), 0.0f);
	}
	};

	// The following tests are commented out because if they weren't, the linker would be screaming at us with LNK2001 and LNK2019 errors.

	/*

	TEST_CLASS(UpdateListTests) {
	public:
		TEST_METHOD(node_update) {
			sf::RenderWindow target;

			//Create testing node
			TestNode* testNode = new TestNode();
			::UpdateList::add_node(testNode);

			//Check start conditions
			Assert::IsFalse(testNode->collided);
			Assert::IsFalse(testNode->updated);

			//Run single update
			::UpdateList::update(target, 5);

			//Check final condition
			Assert::IsFalse(testNode->collided);
			Assert::IsTrue(testNode->updated);
		}

		TEST_METHOD(node_collide) {
			sf::RenderWindow target;

			//Create testing node 1
			TestNode* testNode1 = new TestNode();
			testNode1->setPosition(40, 40);
			::UpdateList::add_node(testNode1);

			//Create testing node 2
			TestNode* testNode2 = new TestNode();
			testNode2->setPosition(50, 50);
			::UpdateList::add_node(testNode1);

			//Check start conditions
			Assert::IsFalse(testNode1->collided);
			Assert::IsFalse(testNode1->updated);
			Assert::IsFalse(testNode2->collided);
			Assert::IsFalse(testNode2->updated);

			//Run single update
			::UpdateList::update(target, 5);

			//Check final conditions
			Assert::IsTrue(testNode1->collided);
			Assert::IsTrue(testNode1->updated);
			Assert::IsTrue(testNode2->collided);
			Assert::IsTrue(testNode2->updated);
		}
	};

	TEST_CLASS(Player) {
	public:
		TEST_METHOD(takeDamage) {
			::Player p;
			bool success = false;

			success = p.takeDamage(10);
			Assert::IsTrue(success);
		}

		TEST_METHOD(getKey) {
			::Player p;
			bool success = false;

			p.setKey(true);

			success = p.getKey();
			Assert::IsTrue(success);
		}
	};

	*/
}
