class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    deque<int> snake;
    unordered_set<int> body;
    int width, height, score, foodIndex;
    vector<vector<int>> food;
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        this->food = food;
        this->width = width;
        this->height = height;
        score = foodIndex = 0;
        body.insert(0);
        snake.push_back(0);
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        if (score < 0) return -1;
        int row = snake.front() / width, col = snake.front() % width;
        switch (direction[0]) {
            case 'U':
                row -= 1;
                break;
            case 'L':
                col -= 1;
                break;
            case 'R':
                col += 1;
                break;
            case 'D':
                row += 1;
                break;
            default:
                return -1;
        }
        int newHead = row * width + col;
        body.erase(snake.back());
        
        if (row < 0 || row >= height || col < 0 || col >= width || body.find(newHead) != body.end()) 
        {
            score = -1;
            return -1;
        }
        body.insert(newHead);
        snake.push_front(newHead);
        if (foodIndex < food.size() && row == food[foodIndex][0] && col == food[foodIndex][1]) {
            body.insert(snake.back());
            foodIndex++;                       
            score++;
        } else {
            snake.pop_back();
        }
        return score;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */

 class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    int height, width, foodIndex;
    vector<vector<int>> food;
    unordered_set<int> body;
    deque<int> snake;
    int score = 0;
    
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        this->width = width;
        this->height = height;
        this->food = food;
        foodIndex = 0;       
        snake.push_front(0);
        body.insert(0);
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {          
        if (score < 0) return -1;
        body.erase(snake.back());
        int headX = snake.front() / width, headY = snake.front() % width;        
        switch (direction[0]) {
            case 'U':
                headX--;
                break;
            case 'D':
                headX++;
                break;
            case 'L':
                headY--;
                break;
            case 'R':
                headY++;
                break;
        }
        if (headX < 0 || headX >= height || headY < 0 || headY >= width || body.find(headX * width + headY) != body.end()) {
            score = -1;            
        } else {
            snake.push_front(headX * width + headY);
            body.insert(headX * width + headY);
            if (foodIndex < food.size() && food[foodIndex][0] == headX && food[foodIndex][1] == headY) {
                foodIndex++;
                score++;
                body.insert(snake.back());
            } else {
                snake.pop_back();
            }
        }        
        return score;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */