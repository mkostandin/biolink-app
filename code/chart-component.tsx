import React from 'react'
import { IonHeader, IonContent, IonToolbar, IonTitle, 
    IonCard, IonCardTitle, IonCardSubtitle, IonCardHeader, IonCardContent,
     IonPage, IonButtons, IonBackButton, IonGrid, IonRow, IonCol } from '@ionic/react'
import BioLinkGraph from '../components/BioLinkGraph';
import { Resizable } from 're-resizable'

const Charts: React.FC = () => {
    return(
        <IonPage>
        <IonHeader>
            <IonToolbar>
                <IonButtons slot="start">
                    <IonBackButton defaultHref="/start"/>
                </IonButtons>
                <IonTitle>Charts</IonTitle>
            </IonToolbar>   
        </IonHeader>
            <IonContent>
                <IonGrid>
                    <IonRow>
                        <IonCol>
                        <IonCard>
                                <IonCardHeader>
                                    {/*<IonCardSubtitle>Card Subtitle</IonCardSubtitle>*/}
                                    <IonCardTitle>Progress</IonCardTitle>
                                </IonCardHeader>
                                <IonCardContent>
                                    <Resizable
                                        defaultSize={{
                                        width:339,
                                        height:200,
                                        }}
                                    >
                                        <BioLinkGraph />
                                    </Resizable>
                                </IonCardContent>
                            </IonCard>
                        </IonCol>
                    </IonRow>
                    <IonRow>
                        <IonCol>
                            <IonCard>
                                <IonCardHeader>
                                    {/*<IonCardSubtitle>Card Subtitle</IonCardSubtitle>*/}
                                    <IonCardTitle>Range of Motion</IonCardTitle>
                                </IonCardHeader>
                                <IonCardContent>
                                <img src="https://i.makeagif.com/media/9-11-2015/fZoE_F.gif" />
                                </IonCardContent>
                            </IonCard>
                        </IonCol>
                    </IonRow>
                </IonGrid>
            </IonContent>
        </IonPage>
    );
}

export default Charts;
