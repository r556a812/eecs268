 
m_in.open(file);

if(!(m_in.is_open()))
{
    throw (MazeCreationException("Error"));
}
else
{
    m_in>>m_rows;
    m_in>>m_cols;

    if (m_rows < 1 || m_rows > 999999 || m_cols < 1 || m_cols > 999999)
    {
        throw(MazeCreationException("Error"));
    }

    m_maze = new char*[m_rows];

    for (int i = 0; i < m_rows; i++)
    {
        m_maze[i] = new char[m_cols];
    }


    m_in>>m_startRow;
    m_in>>m_startCol;

    if (m_startRow < 0 || m_startRow > m_rows - 1 || m_startCol < 0 || m_startCol - 1 > m_cols)
    {
        throw (MazeCreationException("Error"));
    }

    readMaze();

    m_in.close();

}




