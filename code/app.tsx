import { Redirect, Route } from 'react-router-dom';
import { IonApp, IonContent, IonHeader, IonIcon, IonLabel, IonRouterOutlet, IonTabBar, IonTabButton, IonTabs, IonTitle, IonToolbar } from '@ionic/react';
import { IonReactRouter } from '@ionic/react-router';
import { AxisOptions, Chart } from 'react-charts'
import { useMemo } from 'react';
import React from 'react';
import { menuOutline, pulseOutline, statsChartOutline, walkOutline} from 'ionicons/icons'

/* Core CSS required for Ionic components to work properly */
import '@ionic/react/css/core.css';

/* Basic CSS for apps built with Ionic */
import '@ionic/react/css/normalize.css';
import '@ionic/react/css/structure.css';
import '@ionic/react/css/typography.css';

/* Optional CSS utils that can be commented out */
import '@ionic/react/css/padding.css';
import '@ionic/react/css/float-elements.css';
import '@ionic/react/css/text-alignment.css';
import '@ionic/react/css/text-transformation.css';
import '@ionic/react/css/flex-utils.css';
import '@ionic/react/css/display.css';

/* Theme variables */
import './theme/variables.css';
import BioLinkGraph from './components/BioLinkGraph';
import Start from './pages/Start';
import Exercises from './pages/Exercises';
import Charts from './pages/Charts';

const App: React.FC = () => {

  return (
  <IonApp>
    <IonReactRouter>
      <IonTabs>
        <IonRouterOutlet>
          <Route path="/start" exact>
            <Start />
          </Route>
          <Route path="/charts" exact>
            <Charts />
          </Route>
          <Route path="/exercises" exact>
            <Exercises />
          </Route>
          <Redirect to="/start"/>
        </IonRouterOutlet>
        <IonTabBar slot="bottom">
          <IonTabButton tab="chart" href="/charts">
            <IonIcon icon={statsChartOutline} />
            <IonLabel>Charts</IonLabel>
          </IonTabButton>
          <IonTabButton tab="excercises" href="/exercises">
            <IonIcon icon={walkOutline} />
            <IonLabel>Exercises</IonLabel>
          </IonTabButton>
        </IonTabBar>
      </IonTabs>
    </IonReactRouter>
  </IonApp>
  )
}

export default App;
