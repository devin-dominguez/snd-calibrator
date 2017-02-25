import React from 'react';

import NavBar from './navbar.jsx';
import MainPanel from './mainPanel.jsx';

class Index extends React.Component {
  render() {
    return (
      <div>
        <NavBar />
        <div className="main">
          <MainPanel />
          {this.props.children}
          <div>
            <img src="http://127.0.0.1:7890/ipvideo" />
          </div>
        </div>
      </div>
    );
  }
}

export default Index;
